#include <stdio.h>

#define INF 99999
#define V 4

int main() {
    int graph[V][V];

    // Prompt user to input graph values
    printf("Enter the values for the %dx%d graph:\n", V, V);
    printf("(Enter %d for infinity)\n", INF);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int value;
            printf("Enter value for graph[%d][%d]: ", i, j);
            scanf("%d", &value);
            graph[i][j] = (value == INF) ? INF : value;
        }
    }

    // Print the graph
    printf("\nThe entered graph is:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF) {
                printf(" INF ");
            } else {
                printf(" %3d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
