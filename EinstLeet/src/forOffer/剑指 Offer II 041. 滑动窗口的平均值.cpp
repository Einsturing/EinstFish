//难度-简单
//队列即可
class MovingAverage
{
private:
    queue<double> q;
    int qsize;
    int cnt;
    double sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        qsize = size;
        cnt = 0;
        sum = 0;
    }

    double next(int val)
    {
        if (cnt == qsize)
        {
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
            return sum / qsize;
        }
        else
        {
            cnt++;
            sum += val;
            q.push(val);
            return sum / cnt;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */