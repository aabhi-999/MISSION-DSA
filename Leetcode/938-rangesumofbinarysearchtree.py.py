class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rangeSumBST(self, root, low, high):
        if not root:
            return 0
        if low > root.val:
            return self.rangeSumBST(root.right, low, high)
        elif root.val > high:
            return self.rangeSumBST(root.left, low, high)
        return self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high) + root.val
