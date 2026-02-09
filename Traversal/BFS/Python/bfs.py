from collections import deque

def bfs(graph, start_node):
    visited = set()
    queue = deque([start_node])
    visited.add(start_node)

    while queue:
        current_node = queue.popleft()
        print(current_node)
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


# /////////////////////////////////////////////////////////////////////////////////////////////////////// test :
def test_simple_graph():
    graph = {
        "A": ["B", "C"],
        "B": ["D"],
        "C": [],
        "D": []
    }

    bfs(graph, "A")

def test_graph_with_cycle():
    graph = {
        1: [2],
        2: [3],
        3: [1, 4],
        4: []
    }

    bfs(graph, 1)

def test_undirected_graph():
    graph = {
        "A": ["B"],
        "B": ["A", "C"],
        "C": ["B"]
    }

    bfs(graph, "A")

def test_directed_graph():
    graph = {
        "A": ["B"],
        "B": ["C"],
        "C": [],
        "D": ["A"]
    }

    bfs(graph, "D")

def test_single_node():
    graph = {
        1: []
    }

    bfs(graph, 1)


def test_disconnected_graph():
    graph = {
        "A": ["B"],
        "B": [],
        "C": ["D"],
        "D": []
    }

    bfs(graph, "A")

def test_full_graph():
    graph = {
        "A": ["B"],
        "B": [],
        "C": ["D"],
        "D": []
    }

    visited = set()
    for node in graph:
        if node not in visited:
            bfs(graph, node)
            visited.add(node)



test_simple_graph()
print("///////////////////////////////////////////////////////////")
test_graph_with_cycle()
print("///////////////////////////////////////////////////////////")
test_undirected_graph()
print("///////////////////////////////////////////////////////////")
test_directed_graph()
print("///////////////////////////////////////////////////////////")
test_single_node()
print("///////////////////////////////////////////////////////////")
test_disconnected_graph()
print("///////////////////////////////////////////////////////////")
test_full_graph()