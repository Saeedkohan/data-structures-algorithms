#include <iostream>
#include <string>
#include <vector>

class Node {
public:
    std::string key;
    int value;
    Node *next;

    Node(std::string key, int value) {
        this->value = value;
        next = nullptr;
        this->key = key;
    }
};

class HashTable {
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    void printTable() {
        for (int i = 0; i < SIZE; i++) {
            std::cout << i << ":" << std::endl;
            if (dataMap[i]) {
                Node *temp = dataMap[i];
                while (temp) {
                    std::cout << "   {" << temp->key << ", " << temp->value << "}" << std::endl;
                    temp = temp->next;
                }
            }
        }
    }


    int hash(std::string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

    void set(std::string key, int value) {
        int index = hash(key);
        Node *newNode = new Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node *temp = dataMap[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(std::string key) {
        int index = hash(key);
        Node *temp = dataMap[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }

    std::vector<std::string> keys() {
        std::vector<std::string> keys;
        for (int i = 0; i < SIZE; i++) {
            Node *temp = dataMap[i];
            while (temp != nullptr) {
                keys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return keys;
    }
};
