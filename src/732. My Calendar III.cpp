//难度-困难
//线段树
class MyCalendarThree
{
private:
    unordered_map<int, int> tree;
    unordered_map<int, int> lazy;

public:
    MyCalendarThree()
    {
    }

    void update(int start, int end, int l, int r, int idx)
    {
        if (start > r || end < l)
            return;
        else if (start <= l && r <= end)
        {
            tree[idx]++;
            lazy[idx]++;
        }
        else
        {
            int l_idx = idx * 2, r_idx = idx * 2 + 1;
            int mid = (l + r) / 2;
            update(start, end, l, mid, l_idx);
            update(start, end, mid + 1, r, r_idx);
            tree[idx] = lazy[idx] + max(tree[l_idx], tree[r_idx]);
        }
    }
    int book(int start, int end)
    {
        update(start, end - 1, 0, 1e9, 1);
        return tree[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */