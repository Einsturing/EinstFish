//难度-中等
//前缀和+二分
class Solution {
private:
    vector<int> points;
    vector<vector<int>> &rects;
    mt19937 gen{random_device{}()};

public:
    Solution(vector<vector<int>> &rects) : rects{rects} {
        this->points.emplace_back(0);
        for(auto &rect : rects) this->points.emplace_back(points.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
    }
    vector<int> pick() {
        uniform_int_distribution<int> dis(0, points.back() - 1);
        int k = dis(gen) % points.back();
        int idx = upper_bound(points.begin(), points.end(), k) - points.begin() - 1;
        k = k - points[idx];
        int a = rects[idx][0], b = rects[idx][1], y = rects[idx][3];
        int row = y - b + 1;
        int pa = k / row;
        int pb = k - row * pa;
        return {a + pa, b + pb};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */