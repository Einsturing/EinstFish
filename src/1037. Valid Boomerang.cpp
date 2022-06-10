//难度-简单
//一些特判
class Solution {
public:
    bool isBoomerang(vector<vector<int>> &points) {
        int x1 = points[0][0];
        int y1 = points[0][1];
        int x2 = points[1][0];
        int y2 = points[1][1];
        int x3 = points[2][0];
        int y3 = points[2][1];
        if (x1 == x2 && x1 == x3) return false;
        if (y1 == y2 && y1 == y3) return false;
        if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)) return false;
        double k1 = (double)(y2 - y1) / (double)(x2 - x1);
        double k2 = (double)(y3 - y2) / (double)(x3 - x2);
        if (k1 == k2) return false;
        return true;
    }
};