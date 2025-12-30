#include <iostream>
#include <__msvc_ostream.hpp>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};


class Queue {
private:
    Node *frontNode;
    Node *rearNode;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        Node *temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return frontNode->data;
    }
};
