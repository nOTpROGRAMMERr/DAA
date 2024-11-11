#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        // Else the target can only be present in the right subarray
        return binarySearch(arr, mid + 1, high, target);
    }

    // Target is not present in array
    return -1;
}

int main() {
	int target;
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter a no to be searched:";
    cin >> target;
    int result = binarySearch(arr, 0, n - 1, target);
    if(result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;
    return 0;
}

