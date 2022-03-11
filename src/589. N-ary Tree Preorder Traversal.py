# 难度-简单
# 简单题，这难度认真的吗。。。
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        def dfs(node):
            if node is None:
                return
            ans.append(node.val)
            for child in node.children:
                dfs(child)
        dfs(root)
        return ans