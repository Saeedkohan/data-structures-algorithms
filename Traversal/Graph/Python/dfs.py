graph = {
    1: [2, 3],
    2: [4, 5],
    3: [6, 7],
    4: [],
    5: [],
    6: [],
    7: []
}

def dfs_recursive(node, visited=None):
    if visited is None:
        visited = set()
    if node in visited:
        return
    visited.add(node)
    print(node, end=' ')
    for neighbor in graph[node]:
        dfs_recursive(neighbor, visited)

def dfs_iterative(start):
    visited = set()
    stack = [start]
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            print(node, end=' ')
            for neighbor in reversed(graph[node]):
                stack.append(neighbor)

print("DFS Recursive:")
dfs_recursive(1)
print()

print("DFS Iterative:")
dfs_iterative(1)
print()
