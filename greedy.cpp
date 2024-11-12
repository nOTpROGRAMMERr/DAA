//#include <stdio.h>
//
//struct Item {
//    int value;
//    int weight;
//};
//
//// Function to swap items
//void swap(struct Item* a, struct Item* b) {
//    struct Item temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// Function to sort items based on value/weight ratio
//void sortItems(struct Item arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            double r1 = (double)arr[j].value / arr[j].weight;
//            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
//            if (r1 < r2) {
//                swap(&arr[j], &arr[j + 1]);
//            }
//        }
//    }
//}
//
//// Function to solve fractional knapsack problem
//double fractionalKnapsack(int W, struct Item arr[], int n) {
//    sortItems(arr, n);
//    
//    int curWeight = 0;
//    double finalValue = 0.0;
//    
//    for (int i = 0; i < n; i++) {
//        if (curWeight + arr[i].weight <= W) {
//            curWeight += arr[i].weight;
//            finalValue += arr[i].value;
//        } else {
//            int remain = W - curWeight;
//            finalValue += arr[i].value * ((double)remain / arr[i].weight);
//            break;
//        }
//    }
//    
//    return finalValue;
//}
//
//int main() {
//    int W = 50; // Knapsack capacity
//    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    
//    printf("Maximum value in Knapsack = %.2f\n", fractionalKnapsack(W, arr, n));
//    
//    return 0;
//}

#include <stdio.h>

//O(nlogn) for sorting, followed by 𝑂 ( 𝑛 ) O(n) for selection.
struct Item {
    int value;
    int weight;
};

void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItemsByRatio(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, struct Item items[], int n) {
    sortItemsByRatio(items, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = W - currentWeight;
            totalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50;
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(W, items, n);

    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}

