//难度-中等
//统计最高分的节点数目，dfs
class Solution {
public:
    long maxscore, cnt = 0;
    int n;
    vector<vector<int>> child;
    int dfs(int node) {
        long score = 1;
        long sum = 1;
        for(auto c : child[node]) {
            int sz = dfs(c);
            score *= sz;
            sum += sz;
        }
        if(node != 0) score *= n - sum;
        if(maxscore == score) cnt += 1;
        else if(maxscore < score) {
            maxscore = score;
            cnt = 1;
        }
        return sum;
    }
    int countHighestScoreNodes(vector<int>& parents) {
       this->n = parents.size();
       this->child = vector<vector<int>>(n);
       for(int i = 0; i < n; i++) {
           int p = parents[i];
           if(p != -1) child[p].push_back(i);
       }
       dfs(0);
       return cnt;
    }
};