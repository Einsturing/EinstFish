//难度-中等
//左侧排序，枚举右侧二分
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIdx;
        int len = intervals.size();
        for(int i = 0; i < len; i++) startIdx.emplace_back(intervals[i][0], i);
        vector<int> res(len, -1);
        sort(startIdx.begin(), startIdx.end());
        for(int i = 0; i < len; i++) {
            auto it = lower_bound(startIdx.begin(), startIdx.end(), make_pair(intervals[i][1], 0));
            if(it != startIdx.end()) res[i] = it->second;
        }
        return res;
    }
};