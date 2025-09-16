#include <bits/stdc++.h>
using namespace std;

int N;
int Mcolors;
vector<vector<int>> Adj;
vector<int> color;
//   Time complexity O(m^N)
bool isSafe(int v, int c) {
    for (int u : Adj[v]) {
        if (color[u] == c) return false;
    }
    return true;
}
 // Time complexity O(color^vertex)
bool colorVertex(int v) {
    if (v == N) return true;
    for (int c = 1; c <= Mcolors; ++c) {
        if (!isSafe(v, c)) continue;
        color[v] = c;
        if (colorVertex(v + 1)) return true;
        color[v] = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E;
    if (!(cin >> N >> E >> Mcolors)) {
        return 0;
    }

    Adj.assign(N, {});
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < N && v >= 0 && v < N) {
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
    }

    color.assign(N, 0);

    if (colorVertex(0)) {
        cout << "TRUE\n";
        for (int v = 0; v < N; ++v) {
            cout << v << " -> " << color[v] << "\n";
        }
    } else {
        cout << "FALSE\n";
    }

    return 0;
}

