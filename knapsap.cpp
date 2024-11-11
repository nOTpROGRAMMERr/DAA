#include <stdio.h>


int knapsackDP(int W, int weight[], int value[], int n) {
    int dp[n + 1][W + 1];

   
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                // Maximize the value by either including or excluding the current item
                dp[i][w] = (value[i - 1] + dp[i - 1][w - weight[i - 1]] > dp[i - 1][w]) ? 
                           value[i - 1] + dp[i - 1][w - weight[i - 1]] : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w]; // Exclude the current item
            }
        }

        // Print the DP table after processing each item in a formatted manner
        printf("\nDP table after including item %d (Weight: %d, Value: %d):\n", i, weight[i - 1], value[i - 1]);
        printf("    ");
        for (int y = 0; y <= W; y++) {
            printf("%4d ", y); 
        }
        printf("\n");

        for (int x = 0; x <= n; x++) {
            printf("%4d|", x); 
            for (int y = 0; y <= W; y++) {
                printf("%4d ", dp[x][y]);
            }
            printf("\n");
        }
    }

    return dp[n][W]; // The maximum value for the full capacity and all items
}

int main() {
    int n = 4; // Number of items
    int W = 8   ; // Knapsack capacity
    int weight[] = {1,3,5,7}; 
    int value[] = {2,4,7,10}; 
    int max_value = knapsackDP(W, weight, value, n); 
    printf("\nMaximum value in 0/1 Knapsack: %d\n", max_value);

    return 0;
}