//难度-困难
//有序集合+二分
class RangeModule {
private:
    map<int, int> interval;
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it = interval.upper_bound(left);
        if(it != interval.begin()) {
            auto start = prev(it);
            if(start->second >= right) return;
            if(start->second >= left) {
                left = start->first;
                interval.erase(start);
            }
        }
        while(it != interval.end() && it->first <= right) {
            right = max(right, it->second);
            it = interval.erase(it);
        }
        interval[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = interval.upper_bound(left);
        if(it == interval.begin()) return false;
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = interval.upper_bound(left);
        if(it != interval.begin()) {
            auto start = prev(it);
            if(start->second >= right) {
                int tmp = start->second;
                if(start->first == left) interval.erase(start);
                else start->second = left;
                if(right != tmp) interval[right] = tmp;
                return;
            }
            else if(start->second > left) start->second = left;
        }
        while(it != interval.end() && it->first < right) {
            if(it->second <= right) it = interval.erase(it);
            else {
                interval[right] = it->second;
                interval.erase(it);
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */