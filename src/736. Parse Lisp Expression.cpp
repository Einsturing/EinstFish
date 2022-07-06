//难度-困难
//递归解析
class Solution {
private:
    unordered_map<string, vector<int>> mp;
public:
    int evaluate(string expression) {
        int start = 0;
        return innerEvaluate(expression, start);
    }
    int innerEvaluate(const string& expression, int& start) {
        if(expression[start] != '(') {
            if(islower(expression[start])) {
                string var = parseVar(expression, start);
                return mp[var].back();
            }
            else return parseInt(expression, start);
        }
        int ret;
        start++;
        if(expression[start] == 'l') {
            start += 4;
            vector<string> vars;
            while(true) {
                if(!islower(expression[start])) {
                    ret = innerEvaluate(expression, start);
                    break;
                }
                string var = parseVar(expression, start);
                if(expression[start] == ')') {
                    ret = mp[var].back();
                    break;
                }
                vars.push_back(var);
                start++;
                int e = innerEvaluate(expression, start);
                mp[var].push_back(e);
                start++;
            }
            for(auto var : vars) mp[var].pop_back();
        }
        else if(expression[start] == 'a') {
            start += 4;
            int e1 = innerEvaluate(expression, start);
            start++;
            int e2 = innerEvaluate(expression, start);
            ret = e1 + e2;
        }
        else {
            start += 5;
            int e1 = innerEvaluate(expression, start);
            start++;
            int e2 = innerEvaluate(expression, start);
            ret = e1 * e2;
        }
        start++;
        return ret;
    }
    int parseInt(const string &expression, int &start) {
        int n = expression.size();
        int ret = 0, sign = 1;
        if(expression[start] == '-') {
            sign = -1;
            start++;
        }
        while(start < n && isdigit(expression[start])) {
            ret = ret * 10 + (expression[start] - '0');
            start++;
        }
        return sign * ret;
    }
    string parseVar(const string &expression, int &start) {
        int n = expression.size();
        string ret;
        while(start < n && expression[start] != ' ' && expression[start] != ')') {
            ret.push_back(expression[start]);
            start++;
        }
        return ret;
    }
};