#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Define a structure for a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numNodes;
    Node* adjLists[MAX_NODES];
    int indegree[MAX_NODES];
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    graph->indegree[dest]++;
}

// Function to perform Depth First Search (DFS)
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            DFS(graph, adjVertex, visited);
        temp = temp->next;
    }
}

// Function to perform topological sort using DFS
void topologicalSortDFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;

    Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            topologicalSortDFS(graph, adjVertex, visited);
        temp = temp->next;
    }

    printf("%d ", vertex);
}

// Function to arrange nodes in topological order
void topologicalSort(Graph* graph) {
    int visited[MAX_NODES] = {0};

    printf("Topological order of the nodes: ");
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i])
            topologicalSortDFS(graph, i, visited);
    }
    printf("\n");
}

int main() {
    int choice, startNode;
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Print reachable nodes using DFS\n");
        printf("3. Arrange nodes in topological order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int src, dest;
                printf("Enter source and destination nodes: ");
                scanf("%d %d", &src, &dest);
                if (src >= MAX_NODES || dest >= MAX_NODES || src < 0 || dest < 0) {
                    printf("Invalid input!\n");
                    break;
                }
                if (src > graph->numNodes) graph->numNodes = src + 1;
                if (dest > graph->numNodes) graph->numNodes = dest + 1;
                addEdge(graph, src, dest);
                break;
            }
            case 2: {
                printf("Enter the starting node for DFS: ");
                scanf("%d", &startNode);
                printf("Nodes reachable from %d using DFS: ", startNode);
                int visitedDFS[MAX_NODES] = {0};
                DFS(graph, startNode, visitedDFS);
                printf("\n");
                break;
            }
            case 3: {
                printf("Arranging nodes in topological order:\n");
                topologicalSort(graph);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    // Free allocated memory
    for (int i = 0; i < MAX_NODES; i++) {
        Node* current = graph->adjLists[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}
