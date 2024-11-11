#include <stdio.h>
#include <stdlib.h>

void printFiles(int files[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", files[i]);
    }
    printf("\n");
}

// divide for sorting
int partition(int files[], int low, int high) {
    int pivot = files[high];  
    int i = (low - 1);        

    for (int j = low; j < high; j++) {
        if (files[j] < pivot) {
            i++;
            int temp = files[i];
            files[i] = files[j];
            files[j] = temp;
        }
    }
    int temp = files[i + 1];
    files[i + 1] = files[high];
    files[high] = temp;
    return (i + 1);
}


void quickSort(int files[], int low, int high) {
    if (low < high) {
        int pi = partition(files, low, high);

        
        quickSort(files, low, pi - 1);
        quickSort(files, pi + 1, high);
    }
}


int optimalMerge(int files[], int n) {
    quickSort(files, 0, n - 1);  
    printf("\nFiles after initial sorting: ");
    printFiles(files, n);

    int cost = 0;
    printf("\nCurrent cost: %d\n", cost);

    while (n > 1) {
        
        printf("\nMerging files: %d and %d\n", files[0], files[1]);
        int merged = files[0] + files[1];
        cost += merged;

        printf("Current cost: %d\n", cost);

        files[0] = merged;

        
        for (int i = 1; i < n - 1; i++) {
            files[i] = files[i + 1];
        }
        n--;

        
        quickSort(files, 0, n - 1);

        printf("Files after merging: ");
        printFiles(files, n);
    }

    return cost;
}

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    int *files = (int *)malloc(n * sizeof(int));

    printf("Enter size of files: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int minCost = optimalMerge(files, n);
    printf("\nMinimum cost is: %d\n", minCost);

    free(files);
    return 0;
}
