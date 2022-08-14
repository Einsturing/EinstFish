//难度-简单
//简单遍历
class Solution
{
public:
    int maxScore(string s)
    {
        int score = 0;
        if (s[0] == '0')
            score++;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == '1')
                score++;
        int res = score;
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
                score++;
            if (s[i] == '1')
                score--;
            res = max(res, score);
        }
        return res;
    }
};