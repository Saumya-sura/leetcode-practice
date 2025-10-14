#include <iostream>
#include <queue>
using namespace std;

const int MAX = 20;

void bfs(int n, int adj[MAX][MAX], int start) {
    bool visited[MAX] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < n; ++v) {
            if (adj[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                cout << u << " ";
                for (int v = 0; v < n; ++v) {
                    if (adj[u][v] != 0 && !visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << "\n";
}

void dfsUtil(int n, int adj[MAX][MAX], int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] != 0 && !visited[v]) dfsUtil(n, adj, v, visited);
    }
}

void dfs(int n, int adj[MAX][MAX], int start) {
    bool visited[MAX] = {false};
    cout << "DFS: ";
    dfsUtil(n, adj, start, visited);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfsUtil(n, adj, i, visited);
    }
    cout << "\n";
}

int main() {
    int n;
    cout<<"C-136  \n";
    cout << "Enter number of vertices (max " << MAX << "): ";
    cin >> n;
    if (n <= 0 || n > MAX) {
        cout << "Invalid n\n";
        return 0;
    }
    int adj[MAX][MAX];
    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. Print adjacency matrix\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        int opt; cin >> opt;
        if (opt == 1) {
            int s; cout << "Start vertex (0 to " << n-1 << "): "; cin >> s;
            if (s < 0 || s >= n) cout << "Invalid start\n";
            else bfs(n, adj, s);
        } else if (opt == 2) {
            int s; cout << "Start vertex (0 to " << n-1 << "): "; cin >> s;
            if (s < 0 || s >= n) cout << "Invalid start\n";
            else dfs(n, adj, s);
        } else if (opt == 3) {
            cout << "Adjacency matrix:\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) cout << adj[i][j] << " ";
                cout << "\n";
            }
        } else if (opt == 4) {
            break;
        } else {
            cout << "Invalid option\n";
        }
    }
    return 0;
}
