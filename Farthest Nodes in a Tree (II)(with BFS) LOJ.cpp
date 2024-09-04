#include <bits/stdc++.h>
using namespace std;

const int mx = 3e4 + 10;
vector<pair<int, int>> adj[mx];
int distA[mx], distB[mx],distC[mx];

// BFS to calculate the farthest distance and the farthest node from a start node
int bfs(int start) {
    memset(distA, -1, sizeof(distA));  // Reset distances
    queue<int> q;
    q.push(start);
    distA[start] = 0;

    int farthest_node = start;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto v : adj[node]) {
            if (distA[v.first] == -1) {  // Unvisited node
                distA[v.first] = distA[node] + v.second;
                q.push(v.first);

                if (distA[v.first] > distA[farthest_node]) {
                    farthest_node = v.first;
                }
            }
        }
    }
    return farthest_node;
}
int bfs1(int start) {
    memset(distB, -1, sizeof(distB));  // Reset distances
    queue<int> q;
    q.push(start);
    distB[start] = 0;

    int farthest_node = start;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto v : adj[node]) {
            if (distB[v.first] == -1) {  // Unvisited node
                distB[v.first] = distB[node] + v.second;
                q.push(v.first);

                if (distB[v.first] > distB[farthest_node]) {
                    farthest_node = v.first;
                }
            }
        }
    }
    return farthest_node;
}
int bfs2(int start) {
    memset(distC, -1, sizeof(distC));  // Reset distances
    queue<int> q;
    q.push(start);
    distC[start] = 0;

    int farthest_node = start;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto v : adj[node]) {
            if (distC[v.first] == -1) {  // Unvisited node
                distC[v.first] = distC[node] + v.second;
                q.push(v.first);

                if (distC[v.first] > distC[farthest_node]) {
                    farthest_node = v.first;
                }
            }
        }
    }
    return farthest_node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    for (int tt = 1; tt <= tc; tt++) {
        int nodes;
        cin >> nodes;

        for (int i = 0; i < nodes; i++) {
            adj[i].clear();
        }

        for (int i = 1; i < nodes; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // First BFS from an arbitrary node (node 0)
        int A = bfs(0);

        // Second BFS from the farthest node found (A)
        int B = bfs1(A);

        // Third BFS from the farthest node from A (B)
        bfs2(B);

        // Output the result for each node
        cout << "Case " << tt << ":\n";
        for (int i = 0; i < nodes; i++) {
            cout << max(distB[i], distC[i]) << '\n';
        }
    }

    return 0;
}
