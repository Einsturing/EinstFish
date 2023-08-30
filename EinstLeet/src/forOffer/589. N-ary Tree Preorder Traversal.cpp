//难度-简单
//简单题，这难度认真的吗。。。
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(const Node* n, vector<int>& ans) {
        if(n == nullptr) return;
        ans.push_back(n->val);
        for(auto & c : n->children) dfs(c, ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};