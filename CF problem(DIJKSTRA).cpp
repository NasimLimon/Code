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