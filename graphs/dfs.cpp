#include <iostream>
using namespace std;

void dfs(int node, int adj[][10], bool visited[], int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, n);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    int adj[10][10] = {0};
    bool visited[10] = {false};

    cout << "Enter " << e << " edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start, adj, visited, n);

    return 0;
}

