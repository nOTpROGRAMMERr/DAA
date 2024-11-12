#include <stdio.h>
//O(nlogn)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LeftArray[n1], RightArray[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        LeftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        RightArray[j] = arr[mid + 1 + j];
    }

    // Merge the two arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            arr[k] = LeftArray[i];
            i++;
        } else {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of LeftArray, if any
    while (i < n1) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of RightArray, if any
    while (j < n2) {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int size, int start) {
    for (int i = start; i < size + start; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // find the middle element
        int mid = left + (right - left) / 2;

        // Sort first and second halves 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);

        printf("After merging: ");
        printArray(arr, right - left + 1, left);
    }
}



int main() {
    int arr[] = {10, 7, 8, 9, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n, 0);
    
    mergeSort(arr, 0, n - 1);
    
    printf("\nSorted array is \n");
    printArray(arr, n, 0);
    return 0;
}
