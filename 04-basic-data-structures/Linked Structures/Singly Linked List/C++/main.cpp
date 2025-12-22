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

class LinkedList {
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value) {
        Node *newNode = new Node(value);
        this->head = newNode;
        this->tail = newNode;
        this->length = 1;
    }

    void printList() {
        Node *temp = this->head;
        while (temp) {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    int getLength() {
        return this->length;
    }

    int getTail() {
        return this->tail->value;
    }

    int getHead() {
        return this->head->value;
    }

    void append(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }


    void deleteLast() {
        if (length == 0) return;
        Node *temp = head;

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node *pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            pre->next = nullptr;
        }

        delete temp;
        length--;
    }

    void prepend(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node *get(int index) {
        if (index < 0 && index >= length) return nullptr;
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node *temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 && index >= length) return false;
        if (index == 0) {
            prepend(value);
        }
        if (index == length) {
            append(value);
        }
        Node *newNode = new Node(value);
        Node *temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }
    void deleteNode(int index) {
        if (index < 0 && index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length) return deleteLast();
        Node *prev =get(index - 1);
        Node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse() {
        if (length == 0) return;
        Node *temp = head;
        head=tail;
        tail=temp;
        Node *after=temp->next;
        Node *before=nullptr;
        for (int i = 0; i < length; ++i) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    ~LinkedList() {
        Node *temp = this->head;
        while (temp) {
            head = temp->next;
            delete temp;
            temp = head;
        }
    }
};


int main() {
    LinkedList *myLinkedList = new LinkedList(4);

    std::cout << "your list : " << std::endl;
    myLinkedList->printList();
    std::cout << "head : " << myLinkedList->getHead() << std::endl;
    std::cout << "tail : " << myLinkedList->getTail() << std::endl;
    std::cout << "length : " << myLinkedList->getLength() << std::endl;
    myLinkedList->append(5);
    std::cout << "your list : " << std::endl;
    myLinkedList->printList();
    std::cout << "head : " << myLinkedList->getHead() << std::endl;
    std::cout << "tail : " << myLinkedList->getTail() << std::endl;
    std::cout << "length : " << myLinkedList->getLength() << std::endl;


    return 0;
}
