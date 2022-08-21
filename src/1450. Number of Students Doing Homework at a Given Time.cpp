//难度-简单
//简单题
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int res = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            int s = startTime[i];
            int e = endTime[i];
            if (s <= queryTime && e >= queryTime)
                res++;
        }
        return res;
    }
};