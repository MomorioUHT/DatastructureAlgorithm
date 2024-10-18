#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* next;
} Node;

Node* createEmptyNode(int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = x;
    node->next = NULL;
    return node; 
}

Node** createGraph(int n) {
    Node** adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    return adjList;
}

void addEdge(Node** adjList, int u, int v) {
    Node* node = adjList[u];
    if (node == NULL) {
        node = createEmptyNode(v);
        adjList[u] = node;
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        Node* newNode = createEmptyNode(v);
        node->next = newNode;
    }
}

void deleteGraph(Node** adjList, int n) {
    for (int i = 0; i < n; i++) {
        Node* node = adjList[i];
        while (node) {
            Node* next = node->next;
            free(node);
            node = next;
        }
    }  
    free(adjList);
}

void removeEdge(Node** adjList, int u, int v) {
    Node* node = adjList[u];
    if (node->key == v) {
        adjList[u] = adjList[u]->next;
        free(adjList[u]);
    } else {
        //Two pointers
        Node* prev = node;
        node = node->next;

        while (node->key != v) {
            prev = node;
            node = node->next;
        }

        prev->next = node->next;
        free(node);
    }
}

int isAdjacent(Node** adjList, int u, int v) {
    Node* node = adjList[u];
    while (node != NULL) {
        if (node->key == v) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

Node** addVertex(Node** adjList, int *n, int u) {
    Node** adjList_new = createGraph(u+1);
    for (int i = 0; i < *n; i++) {
        adjList_new[i] = adjList[i];
    }
    deleteGraph(adjList, *n);
    *n = u+1;
    return adjList_new;
}

void removeVertex(Node** adjList, int *n, int u) {
    for (int i = 0; i < *n; i++) {
        if (isAdjacent(adjList, i, u)) {
            removeEdge(adjList, i, u);
        }
    }

    Node* node = adjList[u];
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = node->next;
    }

    adjList[u] = NULL;
    (*n)--;
}

int inDegree(Node** adjList, int n, int u) {
    int deg = 0;

    for (int i = 0; i < n; i++) {
        Node* curr = adjList[i];

        while (curr) {
            if (curr->key == u) {
                deg++;
            }
            curr = curr->next;
        }
    }

    return deg;
}

int outDegree(Node** adjList, int n, int u) {
    int deg = 0;
    Node* curr = adjList[u];

    while (curr) {
        deg++;
        curr = curr->next;
    }

    return deg;
}


void printGraph(Node** adjList, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] head: ", i);
        Node* curr = adjList[i];
        while (curr) {
            printf("-> %d", curr->key);
            curr = curr->next;
        }
        printf("-> NULL\n");
    }
}

int main() {
    int n = 5;  // Number of vertices

    // Create a graph with n vertices
    Node** adjList = createGraph(n);

    // Add edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    // Print the graph
    printf("Graph adjacency list:\n");
    printGraph(adjList, n);

    // Test inDegree and outDegree
    printf("\nIn-degree of vertex 4: %d\n", inDegree(adjList, n, 4));
    printf("Out-degree of vertex 1: %d\n", outDegree(adjList, n, 1));

    // Check adjacency
    printf("\nIs vertex 0 adjacent to vertex 4? %s\n", isAdjacent(adjList, 0, 4) ? "Yes" : "No");
    printf("Is vertex 3 adjacent to vertex 0? %s\n", isAdjacent(adjList, 3, 0) ? "Yes" : "No");

    // Remove an edge
    printf("\nRemoving edge 1->4\n");
    removeEdge(adjList, 1, 4);
    printGraph(adjList, n);

    // Clean up memory
    deleteGraph(adjList, n);

    return 0;
}
