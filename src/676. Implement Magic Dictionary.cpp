//难度-中等
//枚举
class MagicDictionary
{
private:
    vector<string> words;

public:
    MagicDictionary() {}
    void buildDict(vector<string> dictionary)
    {
        words = dictionary;
    }

    bool search(string searchWord)
    {
        for (auto &word : words)
        {
            if (word.size() != searchWord.size())
                continue;
            int cnt = 0;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] != searchWord[i])
                {
                    cnt++;
                    if (cnt > 1)
                        break;
                }
            }
            if (cnt == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */