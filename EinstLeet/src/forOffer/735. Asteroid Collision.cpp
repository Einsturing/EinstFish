//难度-中等
//栈模拟
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> stk;
        for (auto &ast : asteroids)
        {
            bool alive = true;
            if (stk.size() == 0)
                stk.push_back(ast);
            else
            {
                int last = stk.back();
                if ((last < 0 && ast < 0) or (last > 0 && ast > 0) or (last < 0 && ast > 0))
                    stk.push_back(ast);
                else
                {
                    while (!stk.empty() && stk.back() > 0 && abs(stk.back()) <= abs(ast))
                    {
                        if (abs(stk.back()) == abs(ast))
                        {
                            stk.pop_back();
                            alive = false;
                            break;
                        }
                        stk.pop_back();
                    }
                    if (alive && (stk.empty() or stk.back() < 0))
                        stk.push_back(ast);
                }
            }
        }
        return stk;
    }
};