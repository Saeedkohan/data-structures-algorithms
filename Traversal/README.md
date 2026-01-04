# Depth-First Search (DFS) 🌲

**Depth-First Search (DFS)** is a fundamental algorithm used for traversing or searching tree or graph data structures.

The core philosophy of DFS is to **"go deep, head first."**

## 🧠 The Concept

Imagine you are trying to solve a **maze**:
1.  You start at the entrance and choose a path.
2.  You keep walking down that path until you hit a dead end (a wall).
3.  Once you hit a wall, you **backtrack** to the most recent intersection where you had other options.
4.  You try the next available path.
5.  You repeat this until you find the exit or explore the entire maze.

**DFS works exactly like this.** It starts at a root node and explores as far as possible along each branch before backtracking.

## ⚙️ Key Characteristics

* **Strategy:** Exploitation (Depth) over Exploration (Breadth).
* **Data Structure:** Uses a **Stack** (LIFO - Last In, First Out). This can be an explicit stack data structure or the implicit "Call Stack" via recursion.
* **Backtracking:** The process of returning to the previous node when the current path is fully explored.

## 📝 How It Works (Step-by-Step)

1.  **Start:** Pick a starting node (often called the "root" in trees) and push it onto the stack.
2.  **Mark:** Mark the node as "visited" so you don't process it twice.
3.  **Explore:**
    * Look at the node's adjacent neighbors.
    * Pick an unvisited neighbor and move to it immediately.
    * Repeat the process for this new node.
4.  **Backtrack:** If a node has no unvisited neighbors, pop it from the stack (go back) and return to the previous node to check *its* other neighbors.

## 📜 Pseudocode

```text
DFS(Node):
    Mark Node as visited
    Print Node (or process it)
    
    For each neighbor of Node:
        If neighbor is NOT visited:
            DFS(neighbor)