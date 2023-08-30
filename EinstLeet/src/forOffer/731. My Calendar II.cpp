//难度-中等
//遍历模拟
class MyCalendarTwo
{
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> twice;

public:
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        for (auto &[l, r] : twice)
            if (r > start && l < end)
                return false;
        for (auto &[l, r] : booked)
            if (r > start && l < end)
                twice.emplace_back(max(l, start), min(r, end));
        booked.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */