//难度-困难
//周赛第四题，尽量贴墙放，找出箱子增长的规律，根据规律来分维度进行计算
class Solution {
public:
    int minimumBoxes(int n) {
        long long depth = 1, cnt = n;
        int res = 0;
        while((depth + 1) * (depth + 2) * (depth + 3) / 6 <= cnt) depth++;
        res += depth * (depth + 1) / 2;
        cnt -= depth * (depth + 1) * (depth + 2) / 6;
        if(cnt == 0) return res;
        depth = 1;
        while((depth + 1) * (depth + 2) / 2 <= cnt) depth++;
        res += depth;
        cnt -= depth * (depth + 1) / 2;
        if(cnt == 0) return res;
        return res + 1;
    }
};