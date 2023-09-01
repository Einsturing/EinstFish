from pathlib import Path

from nni.experiment import Experiment

search_space = {
    'features': {'_type': 'choice', '_value': [128, 256, 512, 1024]},
    'lr': {'_type': 'loguniform', '_value': [0.0001, 0.1]},
    'momentum': {'_type': 'uniform', '_value': [0, 1]},
}

experiment = Experiment('local')
experiment.config.trial_command = 'python model.py'
experiment.config.trial_code_directory = Path(__file__).parent
experiment.config.search_space = search_space
experiment.config.tuner.name = 'GridSearch'
experiment.config.max_trial_number = 50
experiment.config.trial_concurrency = 2

# Run it!
experiment.run(port=8080, wait_completion=False)
print('Experiment is running. Press Ctrl-C to quit.')
input()