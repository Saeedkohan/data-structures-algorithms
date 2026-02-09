import collections

class GeneralNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child_node):
 

        if isinstance(child_node, GeneralNode):
            self.children.append(child_node)
        else:
            raise ValueError("Child must be a GeneralNode instance")



def preorder_traversal(node, result=None):

    if result is None:
        result = []
        
    if node is None:
        return result
    
    result.append(node.data)
    
    for child in node.children:
        preorder_traversal(child, result)
        
    return result

def postorder_traversal(node, result=None):

    if result is None:
        result = []
        
    if node is None:
        return result
    
    for child in node.children:
        postorder_traversal(child, result)
        
    result.append(node.data)
    
    return result

def level_order_traversal(root):

    if root is None:
        return []
    
    queue = collections.deque([root])
    result = []
    
    while queue:
        current = queue.popleft()
        result.append(current.data)
        
        for child in current.children:
            queue.append(child)
            
    return result


root = GeneralNode('A')
B = GeneralNode('B')
C = GeneralNode('C')
D = GeneralNode('D')
E = GeneralNode('E')
F = GeneralNode('F')
G = GeneralNode('G')

root.add_child(B)
root.add_child(C)
root.add_child(D)

C.add_child(E)
C.add_child(F)

E.add_child(G)

print("--- General Tree Traversals ---")
print(preorder_traversal(root))


print( {postorder_traversal(root)})

print(level_order_traversal(root))
