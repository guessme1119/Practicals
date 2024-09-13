#include <stdio.h>

#define MAX_VERTICES 10

// Adjacency Matrix Graph
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} GraphMatrix;

// Function to initialize the graph
void initGraphMatrix(GraphMatrix* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = 0;
}

// Function to add an edge to the graph
void addEdgeMatrix(GraphMatrix* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;  // For undirected graph
}

// BFS traversal
void BFSMatrix(GraphMatrix* g, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFSMatrixUtil(GraphMatrix* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] && !visited[i])
            DFSMatrixUtil(g, i, visited);
    }
}

void DFSMatrix(GraphMatrix* g, int start) {
    int visited[MAX_VERTICES] = {0};
    DFSMatrixUtil(g, start, visited);
    printf("\n");
}

// Main function for testing
int main() {
    GraphMatrix g;
    initGraphMatrix(&g, 5);

    addEdgeMatrix(&g, 0, 1);
    addEdgeMatrix(&g, 0, 4);
    addEdgeMatrix(&g, 1, 2);
    addEdgeMatrix(&g, 1, 3);
    addEdgeMatrix(&g, 2, 4);
    addEdgeMatrix(&g, 3, 4);

    printf("BFS starting from vertex 0:\n");
    BFSMatrix(&g, 0);

    printf("DFS starting from vertex 0:\n");
    DFSMatrix(&g, 0);

    return 0;
}
