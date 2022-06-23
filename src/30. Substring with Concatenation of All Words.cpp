//难度-困难
//滑动窗口
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size(), n = words[0].size(), len = s.size();
        vector<int> res;
        for(int i = 0; i < n && i + m * n <= len; i++) {
            unordered_map<string, int> mp;
            for(int j = 0; j < m; j++) mp[s.substr(i + j * n, n)]++;
            for(string& word : words) if(--mp[word] == 0) mp.erase(word);
            for(int start = i; start < len - m * n + 1; start += n) {
                if(start != i) {
                    string w = s.substr(start + (m - 1) * n, n);
                    if(++mp[w] == 0) mp.erase(w);
                    w = s.substr(start - n, n);
                    if(--mp[w] == 0) mp.erase(w);
                }
                if(mp.empty()) res.emplace_back(start);
            }
        }
        return res;
    }
};