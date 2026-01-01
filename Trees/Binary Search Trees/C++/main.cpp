class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node *root;

    BinarySearchTree() {
        root = nullptr;
    }


    bool insert(int value) {
        Node *newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }

        Node *currentNode = root;
        while (true) {
            if (newNode->value == currentNode->value) {
                delete newNode;
                return false;
            }

            if (newNode->value < currentNode->value) {
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode;
                    return true;
                }
                currentNode = currentNode->left;
            } else {
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode;
                    return true;
                }
                currentNode = currentNode->right;
            }
        }
    }

    bool contains(int value) {
        Node *currentNode = root;
        while (currentNode) {
            if (value == currentNode->value) {
                return true;
            }
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        return false;
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

private:
    void destroyTree(Node *currentNode) {
        if (currentNode) {
            destroyTree(currentNode->left);
            destroyTree(currentNode->right);
            delete currentNode;
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(5);

    return 0;
}
