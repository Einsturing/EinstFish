import nni
import torch
from torch import nn
from torch.optim.lr_scheduler import ReduceLROnPlateau
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor
import os

os.environ['CUDA_VISIBLE_DEVICES'] = '0'
params = {'features': 512, 'lr': 0.001, 'momentum': 0}
optimized_params = nni.get_next_parameter()
params.update(optimized_params)


class Model(nn.Module):
    def __init__(self, features):
        super(Model, self).__init__()
        self.fc = nn.Sequential(
            nn.Flatten(),
            nn.Linear(28 * 28, features),
            nn.ReLU(),
            nn.Linear(features, features),
            nn.ReLU(),
            nn.Linear(features, 10)
        )

    def forward(self, inputs):
        return self.fc(inputs)


def init_weights(model):
    for m in model.modules():
        if isinstance(m, nn.Conv1d) or isinstance(m, nn.Linear):
            nn.init.xavier_uniform_(m.weight)
            if m.bias is not None:
                nn.init.xavier_uniform_(m.bias.unsqueeze(dim=-1))


def count_parameters(model):
    return sum(p.numel() for p in model.parameters() if p.requires_grad)


def train(dataloader, model, loss_fn, optimizer):
    model.train()
    for batch, (X, y) in enumerate(dataloader):
        optimizer.zero_grad()
        X, y = X.cuda(), y.cuda()
        pred = model(X)
        loss = loss_fn(pred, y)
        loss.backward()
        optimizer.step()


def test(dataloader, model):
    model.eval()
    correct = 0
    with torch.no_grad():
        for X, y in dataloader:
            X, y = X.cuda(), y.cuda()
            pred = model(X)
            correct += (pred.argmax(1) == y).type(torch.float).sum().item()
    return correct / len(dataloader.dataset)


if __name__ == "__main__":
    training_data = datasets.FashionMNIST(root='data', train=True, download=True, transform=ToTensor())
    test_data = datasets.FashionMNIST(root='data', train=False, download=True, transform=ToTensor())
    train_dataloader = DataLoader(training_data, batch_size=64)
    test_dataloader = DataLoader(test_data, batch_size=64)
    model = Model(params['features']).cuda()
    loss_fn = nn.CrossEntropyLoss()
    optimizer = torch.optim.SGD(model.parameters(), lr=params['lr'], momentum=params['momentum'])
    lr_scheduler = ReduceLROnPlateau(optimizer, mode='max', factor=0.5, patience=5, verbose=True)
    best_accuracy = float('-inf')
    no_improvement_count = 0
    torch.autograd.set_detect_anomaly(True)
    num_epochs = 50
    for epoch in range(num_epochs):
        train(train_dataloader, model, loss_fn, optimizer)
        accuracy = test(test_dataloader, model)
        nni.report_intermediate_result(accuracy)
        lr_scheduler.step(accuracy)
        if accuracy > best_accuracy:
            best_accuracy = accuracy
            no_improvement_count = 0
            experiment_id = nni.get_sequence_id()
            torch.save(model, "your_model.pt".format(experiment_id))
        else:
            no_improvement_count += 1
        if no_improvement_count >= 20:
            print("Early stopping. No improvement in validation loss for 20 epochs.")
            break
        print(
            f"Epoch {epoch + 1}/{num_epochs}, Test Accuracy：{accuracy}, Learning Rate: {optimizer.param_groups[0]['lr']}")
    nni.report_final_result(accuracy)
    print("done")
