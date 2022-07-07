//难度-中等
//哈希集合
class Solution {
public:
    vector<string> split(string &s, char ch) {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while(pos < s.size()) {
            while(pos < s.size() && s[pos] == ch) pos++;
            start = pos;
            while(pos < s.size() && s[pos] != ch) pos++;
            if(start < s.size()) res.emplace_back(s.substr(start, pos - start));
        }
        return res;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dic;
        for(auto& root : dictionary) dic.emplace(root);
        vector<string> words = split(sentence, ' ');
        for(auto& word : words) {
            for(int j = 0; j < word.size(); j++) {
                if(dic.count(word.substr(0, j + 1))) {
                    word = word.substr(0, j + 1);
                    break;
                }
            }
        }
        string ans;
        for(int i = 0; i < words.size() - 1; i++) {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }
};