//难度-中等
//dfs
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
    void dfs(TreeNode* root, int H, int& curV, int& curH) {
        if(root == nullptr) return;
        H++;
        dfs(root->left, H, curV, curH);
        dfs(root->right, H, curV, curH);
        if(H > curH) {
            curH = H;
            curV = root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int curV = 0, curH = 0;
        dfs(root, 0, curV, curH);
        return curV;
    }
};