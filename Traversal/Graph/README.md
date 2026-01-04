# 🧠 Depth-First Search (DFS) Algorithm Steps

This diagram illustrates the step-by-step execution of the Depth-First Search (DFS) algorithm on a graph, starting from Node **A**. DFS explores as far as possible along each branch before backtracking. It utilizes a **Stack** data structure (Last-In, First-Out) to manage which nodes to visit next.

---

### Key Concepts

* **Visited Nodes (Dark Blue):** Nodes that have been processed and pushed onto the stack.
* **Current Node (Dark Blue/Outline):** The node currently being explored.
* **Unvisited Nodes (Light Gray):** Nodes not yet encountered.
* **Stack:** Manages the order of exploration, prioritizing depth (LIFO).

### 👣 Execution Flow

The table below details the process, showing how the algorithm moves through the graph and manages the stack:

| Step | Action | Stack Contents | Notes |
| :---: | :--- | :---: | :--- |
| **Start** | Start at Node **A**. Mark **A** as visited and push to the stack. | `[A]` | **A** is the starting point. |
| **1** | Move to **A**'s unvisited neighbor, **B**. Mark **B** as visited. | `[A, B]` | Moving deeper into the graph. |
| **2** | Move to **B**'s unvisited neighbor, **D**. Mark **D** as visited. | `[A, B, D]` | $A \rightarrow B \rightarrow D$ |
| **3** | Move to **D**'s unvisited neighbor, **G**. Mark **G** as visited. | `[A, B, D, G]` | Continuing the current deep path. |
| **4** | **G** has no unvisited neighbors (e.g., **E** is explored later). Pop **G** from the stack. | `[A, B, D]` | **Backtrack** to **D**. |
| **5** | **D** has no unvisited neighbors. Pop **D** from the stack. | `[A, B]` | **Backtrack** to **B**. |
| **6** | **B** finds unvisited neighbor **E**. Mark **E** as visited. | `[A, B, E]` | Exploring a new branch from **B**. |
| **7** | **E** has no unvisited neighbors. Pop **E** from the stack. | `[A, B]` | **Backtrack** to **B**. |
| **8** | **B** finds unvisited neighbor **C**. Mark **C** as visited. | `[A, B, C]` | Exploring the next unvisited branch. |
| **9** | **C** finds unvisited neighbor **F**. Mark **F** as visited. | `[A, B, C, F]` | Reaching maximum depth on this path. |
| **10** | **F** has no unvisited neighbors. Pop **F** from the stack. | `[A, B, C]` | **Backtrack**. |
| **11** | **C** has no unvisited neighbors. Pop **C** from the stack. | `[A, B]` | **Backtrack**. |
| **12** | **B** has no unvisited neighbors left. Pop **B** from the stack. | `[A]` | **Backtrack**. |
| **13** | **A** has no unvisited neighbors left. Pop **A** from the stack. | `[]` | **Finished**. |

### 🚀 DFS Traversal Order

The final order of visitation (the sequence of nodes as they are first processed):

$$A \gg B \gg D \gg G \gg E \gg C \gg F$$