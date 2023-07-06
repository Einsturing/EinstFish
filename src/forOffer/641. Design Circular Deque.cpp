//难度-中等
//模拟
class MyCircularDeque
{
private:
    vector<int> nums;
    int front, rear;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        capacity = k + 1;
        nums = vector<int>(k + 1);
        front = rear = 0;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = (front - 1 + capacity) % capacity;
        nums[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        nums[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return nums[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return nums[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty()
    {
        return rear == front;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */