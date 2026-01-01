#include <iostream>
#include <vector>

int linearSearch(std::vector<int> &arr, int target);

int main() {
    std::vector<int> arr = {-1, 2, 4, 5, 6, 78, 94};
    int target = 78;
    int result = linearSearch(arr, target);
    if (result == -1) {
        std::cout << "Element not found" << std::endl;
    } else {
        std::cout << "Element is present at index " << result;
    }
    return 0;
}


int linearSearch(std::vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
