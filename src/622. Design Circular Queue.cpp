//难度-中等
//模拟
class MyCircularQueue
{
private:
    int maxLen;
    vector<int> q;

public:
    MyCircularQueue(int k)
    {
        maxLen = k;
    }

    bool enQueue(int value)
    {
        if (q.size() == maxLen)
            return false;
        q.emplace_back(value);
        return true;
    }

    bool deQueue()
    {
        if (q.size() == 0)
            return false;
        q.erase(q.begin());
        return true;
    }

    int Front()
    {
        if (q.size() == 0)
            return -1;
        return q[0];
    }

    int Rear()
    {
        if (q.size() == 0)
            return -1;
        return q[q.size() - 1];
    }

    bool isEmpty()
    {
        if (q.size() == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (q.size() == maxLen)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */