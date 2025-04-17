
#include <iostream>
#include <vector>
#include <algorithm> // For std::min

using namespace std;

// Exponential Search (Iterative)
int exponentialSearch(const vector<int>& arr, int target) {
    int n = arr.size();

    // Handle edge cases: empty array or target at the beginning
    if (n == 0) return -1;
    if (arr[0] == target) return 0;

    // 1. Find a range where the target *might* be present
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2; // Exponential jump
    }

    // 2. Perform binary search within the range [i/2, min(i, n-1)]
    int left = i / 2;
    int right = min(i, n - 1);

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found!
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = exponentialSearch(arr, target);

    if (result == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result << endl;
    }

    // Additional test cases
    cout << "Target 44: Index " << exponentialSearch(arr, 44) << endl;  // Not found
    cout << "Target 2: Index " << exponentialSearch(arr, 2) << endl;    // First element
    cout << "Target 40: Index " << exponentialSearch(arr, 40) << endl;  // Last element

    return 0;
}