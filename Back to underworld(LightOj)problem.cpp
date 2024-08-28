//https://lightoj.com/problem/back-to-underworld
#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e5 + 10;
vector<int> adj[mx];
int visited[mx];
int isNode[mx];
int cnt1, cnt2;

void bfs(int start, int col) {
    visited[start] = 1;
    if (col == 1) {
        cnt1++;
    }
    cnt2++;
    
    int temp = (col == 1) ? 2 : 1;

    for (auto y : adj[start]) {
        if (visited[y] == 0) {
            bfs(y, temp);
        }
    }
}

int main() {
    optimize();
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        for (int j = 1; j < mx; j++) {
            adj[j].clear();
            visited[j] = 0;
            isNode[j] = 0;
        }

        int m;
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            isNode[u] = 1;
            isNode[v] = 1;
        }

        int ans = 0;
        for (int j = 1; j < mx; j++) {
            if (visited[j] == 0 && isNode[j] == 1) {
                cnt1 = 0;
                cnt2 = 0;
                bfs(j, 1);
                ans += max(cnt1, cnt2 - cnt1);
            }
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
