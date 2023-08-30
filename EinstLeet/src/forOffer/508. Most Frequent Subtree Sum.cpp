//难度-中等
//dfs+哈希表
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
    unordered_map<int, int> cnt;
    int maxcnt = 0;
    int dfs(TreeNode* node) {
        if(node == nullptr) return 0;
        int sum = node->val + dfs(node->left) + dfs(node->right);
        maxcnt = max(maxcnt, ++cnt[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        dfs(root);
        for(auto& [s, c] : cnt) if(c == maxcnt) res.emplace_back(s);
        return res;
    }
};