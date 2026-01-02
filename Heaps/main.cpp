#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    int leftChild(int index) {
        return index * 2 + 1;
    }

    int rightChild(int index) {
        return index * 2 + 2;
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2) {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void printHeap() {
        std::cout << "\n[";
        for (int i = 0; i < heap.size(); i++) {
            std::cout << heap[i];
            if (i < heap.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;
        while (current > 0 && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void sinkDown(int index) {
        int maxIndex = index;
        while (true) {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
                maxIndex = leftIndex;
            }
            if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
                maxIndex = rightIndex;
            }
            if (maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            } else {
                return;
            }
        }
    }

    int remove() {
        if (heap.empty()) {
            return INT_MIN;
        }
        int max = heap.front();
        if (heap.size() == 1) {
            heap.pop_back();
        } else {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return max;
    }
};
