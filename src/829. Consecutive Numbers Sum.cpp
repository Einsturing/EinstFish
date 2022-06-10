//难度-困难
//数学题
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        int maxn = 2 * n;
        for (int k = 1; k * (k + 1) <= maxn; k++) {
            if (k % 2 == 1) {
                if (n % k == 0) ans++;
            }
            else if (n % k != 0 && (2 * n) % k == 0) ans++;
        }
        return ans;
    }
};