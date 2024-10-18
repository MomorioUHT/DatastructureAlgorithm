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