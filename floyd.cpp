#include <stdio.h>
//O(V3)
#define INF 99999
#define V 4

void printSolution(int dist[][V]) {
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // if (dist[i][j] == INF)
            //     printf("%7s", "INF");
            // else
            //     printf("%7d", dist[i][j]);
            printf(" %d ",dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        printf("Shortest distances between every pair of vertices after iteration %d\n", k);
        printSolution(dist);
    }
    printf("Final \n");
    printf("Shortest distances between every pair of vertices:\n");
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 8, INF, 1},
        {INF, 0, 1, INF},
        {4, INF, 0, INF},
        {INF, 2, 9, 0}
    };

    floydWarshall(graph);

    return 0;
}
