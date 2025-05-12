class Solution(object):
    def diameterOfBinaryTree(self, root):
        self.max_diameter = 0

        def depth(node):
            if not node:
                return 0
            left_depth = depth(node.left)
            right_depth = depth(node.right)
            self.max_diameter = max(self.max_diameter, left_depth + right_depth)
            return max(left_depth, right_depth) + 1

        depth(root)
        return self.max_diameter
