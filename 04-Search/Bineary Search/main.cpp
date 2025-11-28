#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &arr, int x);

int main() {
    std::vector<int> arr = {-4, -3, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 14, 27, 67};
    int target = 7;
    int result = binarySearch(arr, target);

    if (result == -1)
        std::cout << "Element is not present in array";
    else
        std::cout << "Element is present at index " << result;
    return 0;
}

int binarySearch(std::vector<int> &arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    return -1;
}