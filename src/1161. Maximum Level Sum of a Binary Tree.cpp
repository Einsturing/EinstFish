//难度-中等
// bfs
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
    int maxLevelSum(TreeNode *root)
    {
        vector<TreeNode *> q = {root};
        int res = 1;
        int maxSum = root->val;
        for (int i = 1; !q.empty(); i++)
        {
            vector<TreeNode *> tmpq;
            int sum = 0;
            for (auto node : q)
            {
                sum += node->val;
                if (node->left)
                    tmpq.emplace_back(node->left);
                if (node->right)
                    tmpq.emplace_back(node->right);
            }
            if (sum > maxSum)
            {
                res = i;
                maxSum = sum;
            }
            q = move(tmpq);
        }
        return res;
    }
};