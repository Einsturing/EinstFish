//难度-中等
//二叉树递归即可
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
    bool haveOne(TreeNode *root)
    {
        bool flag = false;
        if (root == nullptr)
            return false;
        if (root->val == 1)
            flag = true;
        if (!haveOne(root->left))
            root->left = nullptr;
        if (!haveOne(root->right))
            root->right = nullptr;
        if (root->left || root->right)
            flag = true;
        return flag;
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        haveOne(root);
        if (root->val == 0 && !root->left && !root->right)
            root = nullptr;
        return root;
    }
};