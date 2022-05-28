//难度-简单
//用栈即可
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string ans;
        for(auto c : s) {
            if(c == ')') stk.pop();
            if(!stk.empty()) ans.push_back(c);
            if(c == '(') stk.push(c);
        }
        return ans;
    }
};