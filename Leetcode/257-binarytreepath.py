 class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        def dfs(node, path): 
            if not node.left and not node.right:
                paths.append(path + str(node.val))
                return
            if node.left:
                dfs(node.left, path + str(node.val) + "->")
            if node.right:
                dfs(node.right, path + str(node.val) + "->")
        
        paths = []
        if root:
            dfs(root, "")
        return paths
