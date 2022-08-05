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
    void dfs(TreeNode *father, TreeNode *now, int val, bool l, int cnt, int depth)
    {
        if (now == nullptr && cnt != depth)
            return;
        if (cnt == depth)
        {
            TreeNode *tmp = new TreeNode(val);
            if (l)
            {
                tmp->left = now;
                father->left = tmp;
            }
            else
            {
                tmp->right = now;
                father->right = tmp;
            }
            return;
        }
        dfs(now, now->left, val, 1, cnt + 1, depth);
        dfs(now, now->right, val, 0, cnt + 1, depth);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(nullptr, root, val, 1, 1, depth);
        return root;
    }
};