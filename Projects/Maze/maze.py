class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

    def is_empty(self):
        return len(self.items) == 0

def is_valid_move(maze, visited, x, y):
    n = len(maze)
    return 0 <= x < n and 0 <= y < n and maze[x][y] == 0 and not visited[x][y]

def solve_maze(maze):
    n = len(maze)
    stack = Stack()
    visited = [[False]*n for _ in range(n)]
    stack.push((0, 0, [(0, 0)]))
    visited[0][0] = True
    directions = [(-1,0),(1,0),(0,-1),(0,1)]

    while not stack.is_empty():
        x, y, path = stack.pop()
        if (x, y) == (n-1, n-1):
            return True, path
        for dx, dy in directions:
            nx, ny = x+dx, y+dy
            if is_valid_move(maze, visited, nx, ny):
                visited[nx][ny] = True
                stack.push((nx, ny, path + [(nx, ny)]))
    return False, []

def print_maze_with_path(maze, path):
    maze_copy = [row[:] for row in maze]
    for x, y in path:
        maze_copy[x][y] = '*'
    for row in maze_copy:
        print(' '.join(str(cell) for cell in row))

maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0]
]
has_path, path = solve_maze(maze)
if has_path:
    print("Path found")
    print("Path coordinates:", path)
    print("\nMaze with path:")
    print_maze_with_path(maze, path)
else:
    print("No path exists")