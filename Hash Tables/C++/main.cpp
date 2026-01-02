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
    Node *dataMap[SIZE] = {nullptr};

public:
    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node *temp = dataMap[i];
            while (temp) {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }

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


    int hash(const std::string &key) {
        int hash = 0;
        for (char c: key) {
            hash = (hash + int(c) * 23) % SIZE;
        }
        return hash;
    }

    void set(const std::string &key, int value) {
        int index = hash(key);
        Node *temp = dataMap[index];

        while (temp) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(key, value);
        newNode->next = dataMap[index];
        dataMap[index] = newNode;
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

int main() {
    HashTable ht;

    ht.set("apple", 10);
    ht.set("banana", 20);
    ht.set("orange", 30);
    ht.set("grape", 40);
    ht.set("lemon", 50);


    ht.set("elppa", 100);
    ht.set("ananab", 200);

    ht.printTable();


    std::cout << "apple  -> " << ht.get("apple") << std::endl;
    std::cout << "banana -> " << ht.get("banana") << std::endl;
    std::cout << "orange -> " << ht.get("orange") << std::endl;
    std::cout << "grape  -> " << ht.get("grape") << std::endl;
    std::cout << "lemon  -> " << ht.get("lemon") << std::endl;


    std::cout << "watermelon -> " << ht.get("watermelon") << std::endl;

    ht.set("apple", 999);
    std::cout << "apple -> " << ht.get("apple") << std::endl;

    std::vector<std::string> allKeys = ht.keys();
    for (const auto& key : allKeys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    ht.printTable();

    return 0;
}
