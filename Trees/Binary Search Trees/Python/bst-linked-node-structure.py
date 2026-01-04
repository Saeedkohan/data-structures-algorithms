class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        new_node = Node(value)
        if self.root is None:
            self.root = new_node
            return True
        current = self.root
        while True:
            if value == current.value:
                return False
            if value < current.value:
                if current.left is None:
                    current.left = new_node
                    return True
                current = current.left
            else:
                if current.right is None:
                    current.right = new_node
                    return True
                current = current.right

    def search(self, value):
        current = self.root
        while current:
            if value == current.value:
                return True
            if value < current.value:
                current = current.left
            else:
                current = current.right
        return False

    def height(self):
        return self._height_recursive(self.root)

    def _height_recursive(self, node):
        if node is None:
            return -1
        left_h = self._height_recursive(node.left)
        right_h = self._height_recursive(node.right)
        return max(left_h, right_h) + 1

    def find_leaves(self):
        return self._find_leaves_recursive(self.root)

    def _find_leaves_recursive(self, node):
        if node is None:
            return []
        if node.left is None and node.right is None:
            return [node.value]

        left_leaves = self._find_leaves_recursive(node.left)
        right_leaves = self._find_leaves_recursive(node.right)
        return left_leaves + right_leaves

    def _find_min_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def delete(self, value):
        self.root = self._delete_recursive(self.root, value)
        return True

    def _delete_recursive(self, node, value):
        if node is None:
            return None

        if value < node.value:
            node.left = self._delete_recursive(node.left, value)
        elif value > node.value:
            node.right = self._delete_recursive(node.right, value)
        else:

            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left


            successor = self._find_min_node(node.right)

            node.value = successor.value

            node.right = self._delete_recursive(node.right, successor.value)

        return node


# ///////////////////////////////////////////////////////////////////////////////////////////////


bst = BinarySearchTree()
values_to_insert = [50, 30, 70, 20, 40, 60, 80]
for val in values_to_insert:
    bst.insert(val)
print("BST created with values: 50(R), 30, 70, 20, 40, 60, 80")
print(f"Insert duplicate (50) successful? {bst.insert(50)}")

print(f"Search for 40 (Exists): {bst.search(40)}")
print(f"Search for 99 (Not Exists): {bst.search(99)}")
print(f"Search for 50 (Root): {bst.search(50)}")

print(f"Calculated height: {bst.height()}")

leaves = bst.find_leaves()
leaves.sort()
print(f"Found leaves (sorted): {leaves}")

print("Deleting 20 (Leaf)...")
bst.delete(20)
print(f"Search for 20 after deletion: {bst.search(20)}")
print(f"New leaves after deleting 20: {bst.find_leaves()}")

print("Deleting 70 (One child)...")
bst.delete(70)
print(f"Search for 70 after deletion: {bst.search(70)}")
print(f"Search for 80 (Now child of 50): {bst.search(80)}")

print("Deleting 50 (Root, Two children)...")
bst.delete(50)
print(f"Search for 50 after deletion: {bst.search(50)}")
print(f"New root value: {bst.root.value}")
print(f"Remaining nodes height: {bst.height()}")
print(f"Final leaves: {bst.find_leaves()}")