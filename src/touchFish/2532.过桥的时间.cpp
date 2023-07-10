/*
 * @lc app=leetcode.cn id=2532 lang=cpp
 *
 * [2532] 过桥的时间
 */

 // @lc code=start
class effiCmp {
public:
    bool operator()(vector<int>& a, vector<int> b) {
        int x = a[0] + a[2];
        int y = b[0] + b[2];
        return x == y ? a[4] < b[4] : x < y;
    }
};

class timeCmp {
public:    
    bool operator()(vector<int>& a, vector<int> b) {
        return a[5] > b[5];
    }
};
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<vector<int>, vector<vector<int>>, effiCmp> wait_left;
        priority_queue<vector<int>, vector<vector<int>>, effiCmp> wait_right;
        priority_queue<vector<int>, vector<vector<int>>, timeCmp> work_left;
        priority_queue<vector<int>, vector<vector<int>>, timeCmp> work_right;
        vector<int> bridge;
        int cnt = 0;
        int cur = 0;
        for (int i = 0; i < k; i++) {
            time[i].push_back(i);
            time[i].push_back(0);
            wait_left.push(time[i]);
        }
        while (cnt < n) {
            while (!work_left.empty() && work_left.top()[5] <= cur) {
                wait_left.push(work_left.top());
                work_left.pop();
            }
            while (!work_right.empty() && work_right.top()[5] <= cur) {
                wait_right.push(work_right.top());
                work_right.pop();
            }
            if (wait_right.empty() && !wait_left.empty()) {
                if (cnt + wait_right.size() + work_right.size() >= n) {
                    cur++;
                    continue;
                }
                bridge = wait_left.top();
                wait_left.pop();
                cur += bridge[0];
                bridge[5] = cur + bridge[1];
                work_right.push(bridge);
            }
            else if (!wait_right.empty()) {
                bridge = wait_right.top();
                wait_right.pop();
                cur += bridge[2];
                bridge[5] = cur + bridge[3];
                work_left.push(bridge);
                cnt++;
            }
            else {
                if (work_left.empty()) {
                    cur = work_right.top()[5];
                }
                else if (work_right.empty()) {
                    cur = work_left.top()[5];
                }
                else {
                    if (work_left.top()[5] < work_right.top()[5]) cur = work_left.top()[5];
                    else cur = work_right.top()[5];
                }
            }
        }
        return cur;
    }
};
// @lc code=end
