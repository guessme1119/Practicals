#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX_VERTICES 10

// Adjacency List Node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Adjacency List
typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        g->adjList[i] = NULL;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

// BFS traversal
void BFS(Graph* g, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = g->adjList[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS traversal
void DFSUtil(Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = g->adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex])
            DFSUtil(g, temp->vertex, visited);
        temp = temp->next;
    }
}

void DFS(Graph* g, int start) {
    int visited[MAX_VERTICES] = {0};
    DFSUtil(g, start, visited);
    printf("\n");
}

// Main function for testing
int main() {
    Graph g;
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);

    printf("BFS starting from vertex 0:\n");
    BFS(&g, 0);

    printf("DFS starting from vertex 0:\n");
    DFS(&g, 0);

    return 0;
}
