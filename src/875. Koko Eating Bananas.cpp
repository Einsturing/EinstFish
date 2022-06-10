//难度-中等
//二分查找
class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1, right = 0;
        for (auto p : piles) right = max(right, p);
        int k = right;
        while (left < right) {
            int speed = (right - left) / 2 + left;
            int time = getTime(speed, piles);
            if (time <= h) {
                k = speed;
                right = speed;
            }
            else left = speed + 1;
        }
        return k;
    }
    int getTime(int speed, vector<int> &piles) {
        int time = 0;
        for (auto p : piles) time += (p + speed - 1) / speed;
        return time;
    }
};