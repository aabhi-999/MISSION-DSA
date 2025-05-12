from collections import deque


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        view = []
        q = deque([(root, 0)])
        while q:
            node, level = q.popleft()
            if not node:
                continue

            if node.left:
                q.append((node.left, level+1))
            if node.right:
                q.append((node.right, level+1))

            if level > len(view) - 1:
                view.append(node.val)
            else:
                view[level] = node.val
        return view
