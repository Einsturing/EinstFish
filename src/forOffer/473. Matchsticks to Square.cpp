//难度-中等
//dfs回溯
class Solution {
public:
    bool dfs(int idx, vector<int>& matchsticks, vector<int>& edges, int len) {
        if(idx == matchsticks.size()) return true;
        for(int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[idx];
            if(edges[i] <= len && dfs(idx + 1, matchsticks, edges, len)) return true;
            edges[i] -= matchsticks[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int length = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(length % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> e(4);
        return dfs(0, matchsticks, e, length / 4);
    }
};