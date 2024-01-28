#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define a structure for a node in the adjacency list representing an edge
struct ListNode {
    int vertex;
    struct ListNode* next;
};

// Define a structure for the graph
struct Graph {
    int numVertices;
    struct ListNode* adjList[MAX_VERTICES];
};

// Function to initialize a graph with a given number of vertices
void initializeGraph(struct Graph* G, int numVertices)
 {
    G->numVertices = numVertices;

    // Initialize adjacency list for each vertex
    for (int i = 0; i < numVertices; ++i) {
        G->adjList[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the adjacency list
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src]; // Insert at the beginning
    graph->adjList[src] = newNode;
}

// Recursive function to perform depth-first search from a given vertex
void dfsHelper(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited
    visited[vertex] = 1;

    printf("%d ", vertex); // Print the visited vertex

    // Traverse all adjacent vertices
    struct ListNode* currentNode = graph->adjList[vertex];
    while (currentNode != NULL) {
        int adjacentVertex = currentNode->vertex;

        // If the adjacent vertex is not visited, recursively visit it
        if (!visited[adjacentVertex]) {
            dfsHelper(graph, adjacentVertex, visited);
        }

        currentNode = currentNode->next;
    }
}

// Function to perform depth-first search starting from a given vertex
void dfs(struct Graph* graph, int startVertex) {
    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    dfsHelper(graph, startVertex, visited);
    printf("\n");
}

int main() {
    // Example usage
    struct Graph myGraph;
    int numVertices = 5;

    // Initialize the graph
    initializeGraph(&myGraph, numVertices);

    // Add edges
    addEdge(&myGraph, 0, 1);
    addEdge(&myGraph, 0, 2);
    addEdge(&myGraph, 1, 3);
    addEdge(&myGraph, 2, 4);

    // Perform DFS starting from vertex 0
    dfs(&myGraph, 0);

    return 0;
}
