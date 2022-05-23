//难度-困难
//bfs每一步的步数加起来
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int bfs(vector<vector<int>>& forest, int fromX, int fromY, int toX, int toY) {
        if(fromX == toX && fromY == toY) return 0;
        int row = forest.size();
        int col = forest[0].size();
        int step = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        q.emplace(fromX, fromY);
        vis[fromX][fromY] = true;
        while(!q.empty()) {
            step++;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                auto [startX, startY] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int nowX = startX + dir[j][0];
                    int nowY = startY + dir[j][1];
                    if(nowX >= 0 && nowX < row && nowY >= 0 && nowY < col) {
                        if(!vis[nowX][nowY] && forest[nowX][nowY] > 0) {
                            if(nowX == toX && nowY == toY) return step;
                            q.emplace(nowX, nowY);
                            vis[nowX][nowY] = true;
                        }
                    } 
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int row = forest.size();
        int col = forest[0].size();
        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) if(forest[i][j] > 1) trees.emplace_back(i, j);
        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b){return forest[a.first][a.second] < forest[b.first][b.second];});
        int fromX = 0;
        int fromY = 0;
        int ans = 0;
        for(int i = 0; i < trees.size(); i++) {
            int toX = trees[i].first;
            int toY = trees[i].second;
            int steps = bfs(forest, fromX, fromY, toX, toY);
            if(steps == -1) return -1;
            ans += steps;
            fromX = toX;
            fromY = toY;
        }
        return ans;
    }
};