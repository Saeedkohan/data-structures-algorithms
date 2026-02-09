class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def dfs_preorder(root):
    if not root:
        return
    stack = [root]
    while stack:
        current = root.pop()
        print(current.data, end=" ")
        if root.right:
            stack.append(root.right)
        if root.left:
            stack.append(root.left)


def dfs_inorder(root):
    if not root:
        return
    stack = []
    current = root

    while stack or current:
        while current:
            stack.append(current)
            current = current.left
        current = stack.pop()
        print(current.data, end=" ")
        current = current.right


def dfs_postorder(root):
    if not root:
        return
    stack1 = [root]
    stack2 = []
    while stack1:
        node = stack1.pop()
        stack2.append(node)
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)
    while stack2:
        print(stack2.pop().data, end=' ')
