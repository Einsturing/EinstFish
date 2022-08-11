//难度-简单
//简单模拟题
class Solution
{
public:
    string reformat(string s)
    {
        vector<char> c;
        vector<char> num;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num.push_back(s[i]);
            else
                c.push_back(s[i]);
        }
        int clen = c.size();
        int numlen = num.size();
        string res = "";
        if (abs(clen - numlen) > 1)
            return res;
        int i = 0, j = 0;
        for (i, j; i < clen && j < numlen; i++, j++)
        {
            if (clen > numlen)
            {
                res += c[i];
                res += num[j];
            }
            else
            {
                res += num[j];
                res += c[i];
            }
        }
        if (i < clen)
            res += c[i];
        if (j < numlen)
            res += num[j];
        return res;
    }
};