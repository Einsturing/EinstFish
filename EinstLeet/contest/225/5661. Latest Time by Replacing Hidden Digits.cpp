//难度-简单
//周赛第一题，简单模拟题
class Solution {
public:
    string maximumTime(string time) {
        string& tmp = time;
        if(tmp[0] == '?') {
            if(tmp[1] == '?') {
                tmp[0] = '2';
                tmp[1] = '3';
            }
            else if(tmp[1] > '3') tmp[0] = '1';
            else tmp[0] = '2';
        }
        if(tmp[1] == '?') {
            if(tmp[0] == '2') tmp[1] = '3';
            else tmp[1] = '9';
        }
        if(tmp[3] == '?') tmp[3] = '5';
        if(tmp[4] == '?') tmp[4] = '9';
        return time;
    }
};