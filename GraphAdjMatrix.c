#include <stdio.h>
#include <stdlib.h>

int** createGraph(int n) {
    int** adjMatrix = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0 ; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    return adjMatrix;
}

void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}

void deleteGraph(int** adjMatrix, int n) {
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

void removeEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 0;
}

int** addVertex(int** adjMatrix, int* n, int u) {
    int** adjMatrix_new = createGraph(u+1);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            if (adjMatrix[i][j] == 1) {
                adjMatrix_new[i][j] = 1;
            }
        }
    }
    deleteGraph(adjMatrix, *n);
    *n = u+1;
    return adjMatrix_new;
}

int isAdjacent(int** adjMatrix, int u, int v) {
    return adjMatrix[u][v] == 1;
}

int** removeVertex(int** adjMatrix, int *n) {
    int** adjMatrix_new = createGraph(*n-1);
    for (int i = 0; i < *n-1; i++) {
        for (int j = 0; j < *n-1; j++) {
            adjMatrix_new[i][j] = adjMatrix[i][j];
        }
    }
    deleteGraph(adjMatrix, *n);
    (*n)--;
    return adjMatrix_new;
}

int inDegree(int** adjMatrix, int n, int u) {
    int deg = 0;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[i][u] == 1) deg++;
    }
    return deg;
}

int outDegree(int** adjMatrix, int n, int u) {
    int deg = 0;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[u][i] == 1) deg++;
    }
    return deg;
}

void printGraph(int** adjMatrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5;  // Number of vertices

    // Create a graph with n vertices
    int** adjMatrix = createGraph(n);

    // Add edges
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    // Print the graph
    printf("Graph adjacency matrix:\n");
    printGraph(adjMatrix, n);

    // Test inDegree and outDegree
    printf("\nIn-degree of vertex 4: %d\n", inDegree(adjMatrix, n, 4));
    printf("Out-degree of vertex 1: %d\n", outDegree(adjMatrix, n, 1));

    // Check adjacency
    printf("\nIs vertex 0 adjacent to vertex 4? %s\n", isAdjacent(adjMatrix, 0, 4) ? "Yes" : "No");
    printf("Is vertex 3 adjacent to vertex 0? %s\n", isAdjacent(adjMatrix, 3, 0) ? "Yes" : "No");

    // Remove an edge
    printf("\nRemoving edge 1->4\n");
    removeEdge(adjMatrix, 1, 4);
    printGraph(adjMatrix, n);

    // Clean up memory
    deleteGraph(adjMatrix, n);

    return 0;
}
