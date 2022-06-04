//难度-简单
//哈希表
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> mp;
        for (string &email : emails)
        {
            string local;
            for (char c : email)
            {
                if (c == '+' || c == '@')
                    break;
                if (c != '.')
                    local += c;
            }
            local += email.substr(email.find('@'));
            mp.emplace(local);
        }
        return mp.size();
    }
};