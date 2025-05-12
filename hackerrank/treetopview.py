

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def topView(root):
    from collections import deque
    if not root:
        return
    top_nodes = {}
    queue = deque([(root, 0)])
    while queue:
        node, hd = queue.popleft()
        if hd not in top_nodes:
            top_nodes[hd] = node.info
        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))
    for hd in sorted(top_nodes):
        print(top_nodes[hd], end=" ")
    print()
