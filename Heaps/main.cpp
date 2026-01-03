#include <iostream>
#include <vector>
#include <climits>

class Heap {
private:
    std::vector<int> heap;

    int leftChild(int index) const {
        return 2 * index + 1;
    }

    int rightChild(int index) const {
        return 2 * index + 2;
    }

    int parent(int index) const {
        return (index - 1) / 2;
    }

    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void sinkDown(int index) {
        while (true) {
            int maxIndex = index;   // نکته‌ی مهم اصلاح‌شده
            int left = leftChild(index);
            int right = rightChild(index);

            if (left < heap.size() && heap[left] > heap[maxIndex]) {
                maxIndex = left;
            }
            if (right < heap.size() && heap[right] > heap[maxIndex]) {
                maxIndex = right;
            }

            if (maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            } else {
                break;
            }
        }
    }

public:

    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }


    int pop() {
        if (heap.empty()) {
            return INT_MIN;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            sinkDown(0);
        }

        return maxValue;
    }

    void printHeap() const {
        std::cout << "[ ";
        for (int v : heap) {
            std::cout << v << " ";
        }
        std::cout << "]\n";
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};


int main() {
    Heap h;


    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(20);
    h.insert(1);
    h.insert(40);

    h.printHeap();

    std::cout << "\nHeap size: " << h.size() << std::endl;

    std::cout << "Popped: " << h.pop() << std::endl; // 40
    h.printHeap();


    std::cout << "Popped: " << h.pop() << std::endl; // 30
    h.printHeap();

    h.insert(50);
    h.insert(15);
    h.printHeap();


    while (!h.isEmpty()) {
        std::cout << "Popped: " << h.pop() << std::endl;
    }

    std::cout << "\nHeap empty? " << (h.isEmpty() ? "Yes" : "No") << std::endl;

    int result = h.pop();
    if (result == INT_MIN) {
        std::cout << "Heap is empty (INT_MIN returned)\n";
    }

    return 0;
}
