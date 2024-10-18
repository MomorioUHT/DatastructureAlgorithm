#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//====================================================================================
// BFS in undirected graph
void bfs(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false); 

    visited[start] = true;

    queue<int> queue;
    queue.push(start);

    int u;

    while (!queue.empty()) {
        u = queue.front(); 
        queue.pop();
        cout << u << endl;

        for (int x : adj[u]) {
            if (!visited[x]) {
                visited[x] = true;
                queue.push(x);
            }
        }
    }
}

//====================================================================================
// DFS in undirected graph
void dfsVisit(vector<vector<int>>& adj, vector<bool>& visited, int curr) {
    visited[curr] = true;
    cout << curr << endl;

    for (int x: adj[curr]) {
        if (!visited[x]) {
            dfsVisit(adj, visited, x);
        }
    }
}

void dfs(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    dfsVisit(adj, visited, start);
}

//====================================================================================

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{
    int V = 5;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);

    cout << "DFS starting from 0 : \n";
    dfs(adj, 0);    

    return 0;
}