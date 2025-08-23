class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        temp = []  
        def dfs(root):
            if not root: return
            dfs(root.left)
            temp.append(root)
            dfs(root.right)
        dfs(root)
        srtd = sorted(n.val for n in temp)  
        for i in range(len(temp)):
            if temp[i].val != srtd[i]:
                temp[i].val = srtd[i]  

