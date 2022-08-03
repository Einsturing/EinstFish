//难度-困难
//思考题
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            string ans = s;
            for (int i = 0; i < s.size(); i++)
            {
                char tmp = s[0];
                s = s.substr(1);
                s += tmp;
                ans = min(ans, s);
            }
            return ans;
        }
        else
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};