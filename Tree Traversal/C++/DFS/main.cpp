#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    void destroyTree(Node* current) {
        if (!current) return;
        destroyTree(current->left);
        destroyTree(current->right);
        delete current;
    }

    void DFSPreorder(Node* current) const {
        if (!current) return;
        cout << current->value << " ";
        DFSPreorder(current->left);
        DFSPreorder(current->right);
    }

    void DFSInorder(Node* current) const {
        if (!current) return;
        DFSInorder(current->left);
        cout << current->value << " ";
        DFSInorder(current->right);
    }

    void DFSPostorder(Node* current) const {
        if (!current) return;
        DFSPostorder(current->left);
        DFSPostorder(current->right);
        cout << current->value << " ";
    }

public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        while (true) {
            if (value == current->value) {
                delete newNode;
                return;
            }

            if (value < current->value) {
                if (!current->left) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }

    bool contains(int value) const {
        Node* current = root;
        while (current) {
            if (value == current->value)
                return true;
            current = (value < current->value)
                        ? current->left
                        : current->right;
        }
        return false;
    }

    void DFSPreorder() const {
        DFSPreorder(root);
        cout << endl;
    }

    void DFSInorder() const {
        DFSInorder(root);
        cout << endl;
    }

    void DFSPostorder() const {
        DFSPostorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    cout << "Contains 7: " << bst.contains(7) << endl;
    cout << "Contains 20: " << bst.contains(20) << endl;

    cout << "DFS Preorder: ";
    bst.DFSPreorder();

    cout << "DFS Inorder: ";
    bst.DFSInorder();

    cout << "DFS Postorder: ";
    bst.DFSPostorder();

    return 0;
}
