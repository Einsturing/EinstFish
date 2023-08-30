//难度-中等
//mt19937，初始化列表
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> rect;
    double cx, cy, r;

public:
    Solution(double radius, double x_center, double y_center) : rect(-radius, radius), cx(x_center), cy(y_center), r(radius) {}

    vector<double> randPoint() {
        while(1) {
            double x = rect(gen), y = rect(gen);
            if(x * x + y * y <= r * r) return {cx + x, cy + y};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */