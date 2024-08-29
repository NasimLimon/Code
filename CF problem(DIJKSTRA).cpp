//dijkstra alogorithm
//https://codeforces.com/problemset/problem/20/C
const int mx = 1e5+123;
ll dist[mx];
vii adj[mx];
int par[mx];

void dijkstra ( int s, int n )
{
    for ( int i = 1; i <= n; i++ ) dist[i] = infLL;
    priority_queue< pll, vll, greater<pll>> pq;

    dist[s] = 0;
    pq.push ( { 0, s } );

    while ( !pq.empty() ) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();

        if ( dist[u] < curD ) continue;

        for ( auto v : adj[u] ) {
            if ( curD + v.S < dist[v.F] ) {
                dist[v.F] = curD + v.S;
                par[v.F] = u;
                pq.push( { dist[v.F], v.F } );
            }
        }
    }
}

int main()
{
	optimize();

    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB ( {v, w} );
        adj[v].PB ( { u, w } );
    }

    dijkstra(1, n);

    if ( dist[n] == infLL ) return cout << "-1\n", 0;

    int u = n;
    vector<int>ans;
    ans.push_back(u);
    while ( par[u] != 0 ) {
        ans.PB ( par[u] );
        u = par[u];
    }

    reverse ( all ( ans ) );

    for ( auto u : ans ) cout << u << " ";
    cout << endl;



	return 0;
}



ORRR
///   ***   ---   |||   In the name of ALLAH   |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e5 + 123;
vector<pair<long long, long long>> adj[mx];
ll dist[mx];
int parent[mx];

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = infLL;
        parent[i] = -1;
    }
    
    dist[s] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll curD = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < curD) continue;

        for (auto p : adj[u]) {
            int v = p.first;
            ll weight = p.second;

            if (curD + weight < dist[v]) {
                dist[v] = curD + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<int> get_path(int n) {
    vector<int> path;
    while (n != -1) {
        path.push_back(n);
        n = parent[n];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    optimize();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB({v, w});
        adj[v].PB({u, w});
    }

    dijkstra(1, n);

    if (dist[n] == infLL) {
        cout << -1 << endl;
    } else {
        vector<int> path = get_path(n);
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
