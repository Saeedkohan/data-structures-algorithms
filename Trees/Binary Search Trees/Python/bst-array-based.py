class ArrayBinarySearchTree:
    def __init__(self):
        self.tree = []

    def insert(self, value):
        if not self.tree:
            self.tree.append(value)
            return

        index = 0
        while True:
            if index >= len(self.tree):
                self.tree.extend([None] * (index - len(self.tree) + 1))

            if self.tree[index] is None:
                self.tree[index] = value
                return

            index = 2 * index + 1 if value < self.tree[index] else 2 * index + 2


    def get_left_child(self, index):
        left = 2 * index + 1
        return self.tree[left] if left< len(self.tree)  else None


    def get_right_child(self, index):
        right = 2 * index + 2
        return  self.tree[right] if right < len(self.tree) else None

    def get_parent(self, index):
        if index == 0:
            return None
        parent = (index - 1) // 2
        return self.tree[parent] if parent < len(self.tree) else None



    def search(self, value):
        index = 0
        while index < len(self.tree )and self.tree[index] is not None :
            if self.tree[index]==value:
                return index
            index = 2 * index + 1 if value < self.tree[index] else 2 * index + 2

        return -1

    def height(self, index=0):

        if index >= len(self.tree) or self.tree[index] is None:
            return -1

        left_height = self.height(2 * index + 1)
        right_height = self.height(2 * index + 2)

        return max(left_height, right_height) + 1

    @staticmethod
    def find_leaves(tree_list):
        leaves = []
        for i, value in enumerate(tree_list):
            if value is None:
                continue

            left = 2 * i + 1
            right = 2 * i + 2

            left_empty = left >= len(tree_list) or tree_list[left] is None
            right_empty = right >= len(tree_list) or tree_list[right] is None

            if left_empty and right_empty:
                leaves.append(value)

        return leaves
