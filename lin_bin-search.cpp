#include <iostream>
using namespace std;

// Function for linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Return the index of the found element
        }
    }
    return -1;  // Return -1 if the element is not found
}

// Function for binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x) {
            return m;
        }

        // If x is greater, ignore left half
        if (arr[m] < x) {
            l = m + 1;
        }
        // If x is smaller, ignore right half
        else {
            r = m - 1;
        }
    }

    // If we reach here, the element was not present
    return -1;
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int x = 1;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test linear search
    int result = linearSearch(arr, n, x);
    if (result != -1) {
        cout << "Element found at index " << result << " using linear search." << endl;
    } else {
        cout << "Element not found in the array using linear search." << endl;
    }

    // Test binary search
    int sortedArr[] = {0, 1, 2, 4, 9}; // Binary search requires a sorted array
    int sortedResult = binarySearch(sortedArr, 0, n - 1, x);
    if (sortedResult != -1) {
        cout << "Element found at index " << sortedResult << " using binary search." << endl;
    } else {
        cout << "Element not found in the array using binary search." << endl;
    }

    return 0;
}

