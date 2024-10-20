#include <iostream>
#include <vector>
using namespace std;

vector<int>* createGraph(int n) {
    return new vector<int>[n];
}

void addEdge(vector<int>* adjList, int u, int v) {
    adjList[u].push_back(v);
}

void printGraph(vector<int>* adjList, int v) {
    for (int i = 0; i < v; i++) {
        cout << "[" << i << "] head";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << " -> " << adjList[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void removeEdge(vector<int>* adjList, int u, int v) {
    for (int i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i] == v) {
            adjList[u].erase(adjList[u].begin() + i);
            return;
        }
    }
}

void addVertex(int &n, int u) {
    n = u + 1;
}

void removeVertex(vector<int>* adjList, int &n, int u) {
    if (u < n-1) return -1;

    for (int i = 0; i < n; i++) {
        removeEdge(adjList, i, u);
    }

    adjList[u].clear();
    n--;
}

bool isAdjacent(vector<int>* adjList, int u, int v) {
    for (int i = 0; i < adjList[u].size(); i++) {
        if (adjList[u][i] == v) {
            return true;
        }
    }
    return false;
}

int inDegree(vector<int>* adjList, int n, int u) {
    int deg = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; i < adjList[i].size(); j++) {
            if (adjList[i][j] == u) {
                deg++;
            }
        }
    }
    return deg;
}

int outDegree(vector<int>* adjList, int u) {
    return adjList[u].size();
}
int main() {
    int n = 5;
    vector<int>* adjList = createGraph(n);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 3);

    printGraph(adjList, n);
    return 0;
}