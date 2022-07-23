//难度-中等
//拓扑排序
class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        int n = nums.size();
        vector<int> indegrees(n + 1);
        vector<unordered_set<int>> graphs(n + 1);
        for (auto &sequence : sequences)
        {
            for (int i = 1; i < sequence.size(); i++)
            {
                int prev = sequence[i - 1];
                int next = sequence[i];
                if (!graphs[prev].count(next))
                {
                    graphs[prev].emplace(next);
                    indegrees[next]++;
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indegrees[i] == 0)
                q.emplace(i);
        while (!q.empty())
        {
            if (q.size() > 1)
                return false;
            int prev = q.front();
            q.pop();
            for (auto &next : graphs[prev])
            {
                indegrees[next]--;
                if (indegrees[next] == 0)
                    q.emplace(next);
            }
        }
        return true;
    }
};