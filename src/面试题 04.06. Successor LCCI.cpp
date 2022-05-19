//难度-中等
//利用二叉搜索树中序遍历递增性质即可
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        int target = p->val;
        TreeNode* cur = root;
        TreeNode* res = nullptr;
        while(cur != nullptr) {
            if(cur->val > target) {
                res = cur;
                cur = cur->left;
            }
            else cur = cur->right;
        }
        return res;
    }
};