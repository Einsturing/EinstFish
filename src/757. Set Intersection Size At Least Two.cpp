//难度-困难
//贪心
class Solution
{
public:
    void find(vector<vector<int>> &intervals, vector<vector<int>> &tmp, int pos, int num)
    {
        for (int i = pos; i >= 0; i--)
        {
            if (intervals[i][1] < num)
                break;
            tmp[i].push_back(num);
        }
    }
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int res = 0;
        int m = 2;
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b)
             {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; });
        vector<vector<int>> tmp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = intervals[i][0], k = tmp[i].size(); k < m; j++, k++)
            {
                res++;
                find(intervals, tmp, i - 1, j);
            }
        }
        return res;
    }
};