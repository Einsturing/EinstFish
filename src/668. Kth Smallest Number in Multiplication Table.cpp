//难度-困难
//找到不超过x的数量，k二分插入
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while(l < r) {
            int x = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 1; i <= m; i++) cnt += min(x / i, n);
            if(cnt >= k) r = x;
            else l = x + 1;
        }
        return l;
    }
};