//难度-中等
// dfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int calDepth(TreeNode *root)
    {
        int h = 0;
        if (root->left)
            h = max(h, calDepth(root->left) + 1);
        if (root->right)
            h = max(h, calDepth(root->right) + 1);
        return h;
    }
    void dfs(vector<vector<string>> &res, TreeNode *root, int r, int c, const int &height)
    {
        res[r][c] = to_string(root->val);
        if (root->left)
            dfs(res, root->left, r + 1, c - (1 << (height - r - 1)), height);
        if (root->right)
            dfs(res, root->right, r + 1, c + (1 << (height - r - 1)), height);
    }
    vector<vector<string>> printTree(TreeNode *root)
    {
        int h = calDepth(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        dfs(res, root, 0, (n - 1) / 2, h);
        return res;
    }
};