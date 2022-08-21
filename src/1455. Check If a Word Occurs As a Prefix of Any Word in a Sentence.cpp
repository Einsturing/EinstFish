//难度-简单
//模拟即可
class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        vector<string> words;
        string tmp = "";
        int ans = -1;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                words.push_back(tmp);
                tmp = "";
            }
            else
                tmp += sentence[i];
        }
        tmp += sentence[sentence.size() - 1];
        words.push_back(tmp);
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(searchWord) == 0)
            {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};