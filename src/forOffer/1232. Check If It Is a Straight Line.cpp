//难度-简单
//简单模拟题，判一下水平和垂直的特殊情况即可
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double x = coordinates[0][0];
        double y = coordinates[0][1];
        double xi = coordinates[1][0];
        double yi = coordinates[1][1];
        double k;
        if(x == xi) k = 1e9;
        else if(y == yi) k = 0;
        else k = (yi - y) / (xi - x);
        for(int i = 2; i < coordinates.size(); i++) {
            double tx = coordinates[i][0];
            double ty = coordinates[i][1];
            double tk;
            if(xi == tx) tk = 1e9;
            else if(yi == ty) tk = 0;
            else tk = (ty - yi) / (tx - xi);
            if(tk != k) return false;
            xi = tx, yi = ty;
        }
        return true;
    }
};