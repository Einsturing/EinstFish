//难度-中等
//利用二叉搜索树性质递归
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(root->val == key) {
            if(!root->left && ! root->right) return nullptr;
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* next = root->right;
            while(next->left) next = next->left;
            root->right = deleteNode(root->right, next->val);
            next->right = root->right;
            next->left = root->left;
            return next;
        }
        return root;
    }
};