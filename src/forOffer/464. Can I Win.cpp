//难度-中等
//状态压缩+搜索
class Solution {
public:
    unordered_map<int, bool> mp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) return false;
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }
    bool dfs(int maxChoosableInteger, int used, int desiredTotal, int current) {
        if(!mp.count(used)) {
            bool res = false;
            for(int i = 0; i < maxChoosableInteger; i++) {
                if(((used >> i) & 1) == 0) {
                    if(i + 1 + current >= desiredTotal) {
                        res = true;
                        break;
                    }
                    if(!dfs(maxChoosableInteger, used | (1 << i), desiredTotal, i + 1 + current)) {
                        res = true;
                        break;
                    }
                }
            }
            mp[used] = res;
        }
        return mp[used];
    }
};