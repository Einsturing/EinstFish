//难度-困难
//并查集
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    void Union(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] > rank[rooty])
                parent[rooty] = rootx;
            else if (rank[rootx] < rank[rooty])
                parent[rootx] = rooty;
            else
            {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
};
class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind uf(m + 1);
        for (int num : nums)
        {
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    uf.Union(num, i);
                    uf.Union(num, num / i);
                }
            }
        }
        vector<int> cnts(m + 1);
        int ans = 0;
        for (int num : nums)
        {
            int root = uf.find(num);
            cnts[root]++;
            ans = max(ans, cnts[root]);
        }
        return ans;
    }
};