//难度-简单
//直接模拟遍历即可
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idx(26);
        for(int i=0; i < order.size(); i++) idx[order[i] - 'a'] = i;
        for(int i = 1; i < words.size(); i++) {
            bool yes = false;
            for(int j = 0; j < words[i - 1].size() && j < words[i].size(); j++) {
                int pre = idx[words[i - 1][j] - 'a'];
                int cur = idx[words[i][j] - 'a'];
                if(pre < cur) {
                    yes = true;
                    break;
                }
                else if(pre > cur) return false;
            }
            if(!yes) if(words[i - 1].size() > words[i].size()) return false;
        }
        return true;
    }
};