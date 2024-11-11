#include <stdio.h>

#define MAX_VERTICES 100

// Function to initialize the adjacency matrix
void initializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph, add this line
}

// Function to display the graph
void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the graph
    initializeGraph(graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Display the graph
    displayGraph(graph, vertices);

    return 0;
}
