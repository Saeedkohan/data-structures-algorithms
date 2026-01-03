#include <iostream>

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


    Node *insert(Node *current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->value) {
            current->left = insert(current->left, value);
        } else if (value > current->value) {
            current->right = insert(current->right, value);
        }

        return current;
    }


    bool contains(Node *current, int value) const {
        if (current == nullptr) return false;
        if (value == current->value) return true;

        if (value < current->value)
            return contains(current->left, value);
        else
            return contains(current->right, value);
    }


    Node *minValueNode(Node *current) {
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }


    Node *deleteNode(Node *current, int value) {
        if (current == nullptr) return nullptr;

        if (value < current->value) {
            current->left = deleteNode(current->left, value);
        } else if (value > current->value) {
            current->right = deleteNode(current->right, value);
        } else {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            }

            if (current->left == nullptr) {
                Node *temp = current->right;
                delete current;
                return temp;
            }
            if (current->right == nullptr) {
                Node *temp = current->left;
                delete current;
                return temp;
            }


            Node *successor = minValueNode(current->right);
            current->value = successor->value;
            current->right = deleteNode(current->right, successor->value);
        }
        return current;
    }

public:
    BinarySearchTree() : root(nullptr) {
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};
