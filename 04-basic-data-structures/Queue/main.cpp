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

class Queue {
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue(int value) {
        Node *newNode = new Node(value);
        first = newNode;
        last = first;
        length = 1;
    }

    void printQueue() {
        Node *current = first;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int getFirst() {
        return first->value;
    }

    int getLast() {
        return last->value;
    }

    int getLength() {
        return length;
    }

    void enqueue(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            first = newNode;
            last = first;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int dequeue() {
        if (length == 0) {
            return INT_MIN;
        }
        Node *current = first;
        int dequeueValue = first->value;
        if (length == 1) {
            first = nullptr;
            last = nullptr;
        } else {
            first = first->next;
        }
        delete current;
        length--;
        return dequeueValue;
    }
};

int main() {
    Queue *queue = new Queue(5);


    return 0;
}
