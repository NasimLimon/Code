 //connected component

const int mx = 30;
vi adj[mx];
bool vis[mx];
 
void dfs ( int u )
{
    vis[u] = 1;
    for ( auto v : adj[u] ) {
        if ( !vis[v] ) dfs ( v );
    }
}
 
 
int main()
{
    optimize();
 
    int n, m;
    cin >> n >> m;
 
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
 
        adj[u].PB ( v );
        adj[v].PB ( u );
    }
 
    int cnt = 0;
    for ( int i = 1; i <= n; i++ ) {
        if ( !vis[i] ) {
            dfs ( i );
            cnt++;
        }
    }
 
    cout << cnt << endl;
 
    return 0;
}
