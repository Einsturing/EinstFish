//难度-简单
//简单题
class OrderedStream
{
private:
    vector<string> stream;
    int ptr;

public:
    OrderedStream(int n)
    {
        stream = vector<string>(n);
        ptr = 0;
    }

    vector<string> insert(int idKey, string value)
    {
        int id = idKey - 1;
        stream[id] = value;
        vector<string> res;
        if (ptr == id)
            while (ptr < stream.size() && stream[ptr] != "")
                res.push_back(stream[ptr++]);
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */