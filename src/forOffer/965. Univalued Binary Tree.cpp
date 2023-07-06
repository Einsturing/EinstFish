//难度-简单
//二叉树，递归即可
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
class Solution {
public:
    bool flag = true;
    void isUnival(TreeNode* root, int unival) {
        if(root == nullptr) return;
        int tmpval = root->val;
        if(tmpval != unival) {
            flag = false;
            return;
        }
        isUnival(root->left, unival);
        isUnival(root->right, unival);
    }
    bool isUnivalTree(TreeNode* root) {
        int unival = root->val;
        isUnival(root, unival);
        return flag;
    }
};