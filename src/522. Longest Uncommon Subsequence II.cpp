//难度-中等
//枚举每个字符串
class Solution {
public:
    bool is_sub(const string& s, const string& t) {
        int ps = 0, pt = 0;
        while(ps < s.size() && pt < t.size()) {
            if(s[ps] == t[pt]) ps++;
            pt++;
        }
        return ps == s.size();
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        for(int i = 0; i < n; i++) {
            bool flag = true;
            for(int j = 0; j < n; j++) {
                if(i != j && is_sub(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans = max(ans, static_cast<int>(strs[i].size()));
        }
        return ans;
    }
};