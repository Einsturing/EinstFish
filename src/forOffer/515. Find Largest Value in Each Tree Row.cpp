//难度-中等
//bfs
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            int maxv = INT_MIN;
            while(len-- > 0) {
                auto f = q.front();
                q.pop();
                maxv = max(maxv, f->val); 
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            res.push_back(maxv);
        }
        return res;
    }
};