#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {
    }
};

class BinarySearchTree {
private:
    Node *root;

    void destroyTree(Node *current) {
        if (!current) return;
        destroyTree(current->left);
        destroyTree(current->right);
        delete current;
    }

public:
    BinarySearchTree() : root(nullptr) {
    }


    BinarySearchTree(const BinarySearchTree &) = delete;

    BinarySearchTree &operator=(const BinarySearchTree &) = delete;

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        Node *newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node *current = root;

        while (true) {
            if (value == current->value) {
                delete newNode;
                return;
            }

            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }


    bool contains(int value) const {
        Node *current = root;
        while (current) {
            if (value == current->value)
                return true;
            current = (value < current->value)
                          ? current->left
                          : current->right;
        }
        return false;
    }


    void BFS() const {
        if (!root) return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *current = q.front();
            q.pop();

            cout << current->value << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
};


int main() {
    BinarySearchTree bst;

    // insert
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(10); // duplicate

    // contains
    cout << boolalpha;
    cout << "Contains 7:  " << bst.contains(7) << endl;
    cout << "Contains 20: " << bst.contains(20) << endl;

    // BFS
    cout << "BFS traversal: ";
    bst.BFS();

    return 0;
}
