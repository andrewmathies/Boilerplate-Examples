# https://leetcode.com/problems/invert-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        return self.help(root)
    
    def help(self, node):
        if not node:
            return None
        
        temp = node.left
        node.left = node.right
        node.right = temp
        
        self.help(node.left)
        self.help(node.right)
        
        return node
        