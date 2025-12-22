#include <iostream>

class Node {
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList() {
        Node *current = head;
        while (current) {
            std::cout << current->value << "\n";
            current = current->next;
        }
    }

    int getLength() {
        return length;
    }

    int getHead() {
        return head->value;
    }

    int getTail() {
        return tail->value;
    }

    void append(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node *current = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete current;
        length--;
    }


    void prepend(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node *current = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete current;
        length--;
    }

    Node *get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node *current = head;
        if (index < length / 2) {
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = tail;
            for (int i = index; i > index; i--) {
                current = current->prev;
            }
        }
        return current;
    }

    bool set(int index, int value) {
        Node *current = get(index);
        if (current) {
            current->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            append(value);
            return true;
        }
        if (length == index) {
            append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *before = get(index - 1);
        Node *after = before->next;
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
        return true;
    }

    void deletNode(int index) {
        if (index < 0 || index > length) return;
        if (index == 0) {
            return deleteFirst();
        }
        if (index == length - 1) {
            return deleteLast();
        }
        Node *current = get(index);
        current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
        length--;
    }
};


int main() {
    DoublyLinkedList list = DoublyLinkedList(10);

    return 0;
}
