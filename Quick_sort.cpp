#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array and return the partition index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform quick sort
void quick_sort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Print the array after partitioning
        printf("After partitioning around pivot %d: ", arr[pi]);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quick_sort(arr, low, pi - 1, size);
        quick_sort(arr, pi + 1, high, size);
    }
}

// Function to print the array
void print_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Quick Sort \n");
    printf("Given array is \n");
    print_array(arr, n);
    quick_sort(arr, 0, n - 1, n);
    printf("Sorted array is \n");
    print_array(arr, n);
    return 0;
}
