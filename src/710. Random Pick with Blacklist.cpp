//难度-困难
//映射
class Solution {
    unordered_map<int, int> mp;
    int bound;
public:
    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        bound = n - m;
        unordered_set<int> black;
        for(int b : blacklist) if(b >= bound) black.emplace(b);
        int w = bound;
        for(int b : blacklist) {
            if(b < bound) {
                while(black.count(w)) w++;
                mp[b] = w++;
            }
        }
    }
    
    int pick() {
        int x = rand() % bound;
        return mp.count(x) ? mp[x] : x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */