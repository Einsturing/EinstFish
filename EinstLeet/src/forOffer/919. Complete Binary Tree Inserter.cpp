//难度-中等
//队列
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
class CBTInserter
{
private:
    queue<TreeNode *> tree;
    TreeNode *root;

public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            if (!(tmp->left && tmp->right))
                tree.push(tmp);
        }
    }

    int insert(int val)
    {
        TreeNode *child = new TreeNode(val);
        TreeNode *tmp = tree.front();
        int res = tmp->val;
        if (!tmp->left)
            tmp->left = child;
        else
        {
            tmp->right = child;
            tree.pop();
        }
        tree.push(child);
        return res;
    }

    TreeNode *get_root()
    {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */