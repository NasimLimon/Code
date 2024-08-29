//https://lightoj.com/problem/farthest-nodes-in-a-tree
//                        In the name of Supreme and merciful God  
#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
const long long infLL = 9000000000000000000LL;

vector<pair<long long, long long>> adj[mx];
long long dist[mx];
int node;
long long ans, total;

void dijkstra(int start) {
    for (int k = 0; k < mx; k++) {
        dist[k] = infLL;
    }
    dist[start] = 0;
    ans = -1;
    total = -1;
    
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        long long curD = pq.top().first;
        int Nod = pq.top().second;
        pq.pop();
        
        if (curD > dist[Nod]) continue;
        
        for (auto p : adj[Nod]) {
            int nextNode = p.first;
            long long weight = p.second;
            
            if (curD + weight < dist[nextNode]) {
                dist[nextNode] = curD + weight;
                
                if (dist[nextNode] > total) {
                    ans = nextNode;
                    total = dist[nextNode];
                }
                
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    for (int i = 1; i <= tc; i++) {
        cin >> node;
        
        for (int j = 0; j <= node; j++) {
            adj[j].clear();
        }
        
        for (int j = 1; j < node; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        dijkstra(0);    // First Dijkstra to find the farthest node from node 0
        dijkstra(ans);   // Second Dijkstra to find the longest path
        
        cout << "Case " << i << ": " << total << endl;
    }
    
    return 0;
}
