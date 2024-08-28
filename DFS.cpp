const int mx = 1e5+123;
bool vis[mx];
vector<int> adj[mx];

void dfs ( int u )
{
    vis[u] =  1;

    for ( auto v : adj[u] ) {
        if ( vis[v] == 0 ) {
            dfs ( v );
        }
    }

    return;
}

int main()
{
    optimize();


    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back ( v );
        adj[v].push_back ( u );
    }

    dfs ( 1 );


    return 0;
}
