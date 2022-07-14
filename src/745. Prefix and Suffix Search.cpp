//难度-困难
//暴力哈希
class WordFilter
{
private:
    unordered_map<string, int> dict;

public:
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            int m = words[i].size();
            for (int pre = 1; pre <= m; pre++)
            {
                for (int suf = 1; suf <= m; suf++)
                {
                    string s = words[i].substr(0, pre) + '+' + words[i].substr(m - suf);
                    dict[s] = i;
                }
            }
        }
    }

    int f(string pref, string suff)
    {
        string s = pref + '+' + suff;
        return dict.count(s) ? dict[s] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */