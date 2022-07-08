//难度-简单
//简单题
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int ji = 0;
        int ou = 0;
        for (int i = 0; i < position.size(); i++)
        {
            if (position[i] % 2)
                ji++;
            else
                ou++;
        }
        return min(ji, ou);
    }
};