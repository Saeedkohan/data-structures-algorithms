class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def dfs_preorder(root):
    if not root:
        return
    print(root.data, end=' ')
    dfs_preorder(root.left)
    dfs_preorder(root.right)

def dfs_inorder(root):
    if not root:
        return
    dfs_inorder(root.left)
    print(root.data, end=' ')
    dfs_inorder(root.right)

def dfs_postorder(root):
    if not root:
        return
    dfs_postorder(root.left)
    dfs_postorder(root.right)
    print(root.data, end=' ')

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print("Preorder:")
dfs_preorder(root)
print()

print("Inorder:")
dfs_inorder(root)
print()

print("Postorder:")
dfs_postorder(root)
print()
