#include <iostream>

class Node {
public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node *top;
    int height;

public:
    Stack(int value) {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printStack() {
        Node *current = top;
        while (current) {
            std::cout << current->value << "\n";
            current = current->next;
        }
    }

    int getHeight() {
        return height;
    }

    int getTop() {
        return top->value;
    }

    void push(int value) {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop() {
        if (height==0) return -1;
        Node *current = top;
        int poppedValue = top->value;
        top = top->next;
        delete current;
        height--;
        return poppedValue;
    }
};
