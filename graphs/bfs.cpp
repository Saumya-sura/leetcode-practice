#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    int adj[n][n] = {0};

    cout << "Enter " << e << " edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // for undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    bool visited[n] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}
