//难度-中等
//模拟
class Solution
{
public:
    string fractionAddition(string expression)
    {
        long long up = 0, down = 1;
        int i = 0, n = expression.size();
        while (i < n)
        {
            long long upnew = 0, sign = 1;
            if (expression[i] == '-' || expression[i] == '+')
            {
                sign = expression[i] == '-' ? -1 : 1;
                i++;
            }
            while (i < n && isdigit(expression[i]))
            {
                upnew = upnew * 10 + expression[i] - '0';
                i++;
            }
            upnew = sign * upnew;
            i++;
            long long downnew = 0;
            while (i < n && isdigit(expression[i]))
            {
                downnew = downnew * 10 + expression[i] - '0';
                i++;
            }
            up = up * downnew + upnew * down;
            down *= downnew;
        }
        if (up == 0)
            return "0/1";
        long long g = gcd(abs(up), down);
        return to_string(up / g) + "/" + to_string(down / g);
    }
};