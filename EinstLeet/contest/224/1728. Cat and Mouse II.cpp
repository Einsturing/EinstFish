//难度-中等
//周赛第四题，大模拟，记忆化dp搜索，建议放弃
class Solution {
public:
    int height, weight;
    int maxn;
    vector<vector<vector<int>>> dp;
    vector<string> g;
    int cj, mj;
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int cal(pair<int, int>& cat, pair<int, int>& mouse) {
        int c = cat.first * weight + cat.second;
        int m = mouse.first * weight + mouse.second;
        return c * height * weight + m;
    }
    int search(pair<int, int> cat, pair<int, int> mouse, int round, int isMouse) {
        int cf = cat.first, cs = cat.second;
        int mf = mouse.first, ms = mouse.second;
        if(round == maxn + 1) return 0;
        if(isMouse && g[mf][ms] == 'F') return 1;
        if(!isMouse && g[cf][cs] == 'F') return 1;
        if(isMouse && cf == mf && cs == ms) return 0;
        if(!isMouse && cf == mf && cs == ms) return 1;
        int state = cal(cat, mouse);
        if(dp[isMouse][state][round] >= 0) return dp[isMouse][state][round];
        int ret = 0;
        if(isMouse) {
            int nextround = round;
            if(search(cat, mouse, round, 0) == 0) ret = 1;
            else {
                for(auto [di, dj] : directions) {
                    for(int j = 1; j <= mj; j++) {
                        int fj = mouse.first + j * di;
                        int sj = mouse.second + j * dj;
                        if(fj < 0 || fj >= height || sj < 0 || sj >= weight) break;
                        if(g[fj][sj] == '#') break;
                        if(search(cat, make_pair(fj, sj), round, 0) == 0) {
                            ret = 1;
                            break;
                        }
                    }
                    if(ret == 1) break;
                }
            }
        }
        else {
            int nextround = round + 1;
            if(search(cat, mouse, nextround, 1) == 0) ret = 1;
            else {
                for(auto [di, dj] : directions) {
                    for(int j = 1; j <= cj; j++) {
                        int fj = cat.first + j * di;
                        int sj = cat.second + j * dj;
                        if(fj < 0 || fj >= height || sj < 0 || sj >= weight) break;
                        if(g[fj][sj] == '#') break;
                        if(search(make_pair(fj, sj), mouse, nextround, 1) == 0) {
                            ret = 1;
                            break;
                        }
                    }
                    if(ret == 1) break;
                }
            }
        }
        dp[isMouse][state][round] = ret;
        return ret;
    }
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        height = grid.size();
        weight = grid[0].size();
        maxn = height * weight + 5;
        g = grid;
        cj = catJump, mj = mouseJump;
        dp = vector<vector<vector<int>>> (2, vector<vector<int>> (height * weight * height * weight, vector<int> (maxn + 1, -1)));
        pair<int, int> cat, mouse;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < weight; j++) {
                if(grid[i][j] == 'M') mouse = make_pair(i, j);
                else if(grid[i][j] == 'C') cat = make_pair(i, j);
            }
        }
        int res = search(cat, mouse, 0, 1);
        return res == 1 ? true : false;
    }
};