# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 难度-中等
# 利用二叉搜索树中序遍历递增性质即可
class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> TreeNode:
        target = p.val
        cur = root
        res = None
        while cur != None:
            if cur.val > target:
                res = cur
                cur = cur.left
            else:
                cur = cur.right
        return res