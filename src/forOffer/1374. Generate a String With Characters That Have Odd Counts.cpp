//难度-简单
//简单题
class Solution
{
public:
    string generateTheString(int n)
    {
        string ans = "";
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n - 1; i++)
                ans += 'a';
            ans += 'b';
        }
        else
            for (int i = 1; i <= n; i++)
                ans += 'a';
        return ans;
    }
};