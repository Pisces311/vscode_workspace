class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]):
        if not inorder:
            return None
        node = TreeNode(postorder[-1])
        p = inorder.index(postorder[-1])
        node.left = self.buildTree(inorder[:p], postorder[:p])
        node.right = self.buildTree(inorder[p + 1:], postorder[p:-1])
        return node