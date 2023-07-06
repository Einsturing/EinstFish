//难度-中等
//模拟即可
class Solution {
public:
    bool match(string a, string b) {
        unordered_map<char, char> mp;
        for(int i = 0; i < a.length(); i++) {
            char x = a[i], y = b[i];
            if(!mp.count(x)) mp[x] = y;
            else if(mp[x] != y) return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word : words) if(match(word, pattern) && match(pattern, word)) ans.emplace_back(word);
        return ans;
    }
};