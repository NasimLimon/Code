
//bfs
const int mx = 1e4+123;
vi adj[mx];
int lev[mx];
 
void bfs ( int s )
{
    mem  ( lev, -1 );
    lev[s] = 0;
 
    queue<int> q;
 
    q.push( s );
 
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
 
        for ( auto v : adj[u] ) {
            if ( lev[v] == -1 ) {
                lev[v] = lev[u] + 1;
                q.push( v );
            }
        }
    }
}
 
int main()
{
    optimize();
 
    int T;
    cin >> T;
 
    while ( T-- ) {
        for ( int i = 0; i < mx; i++ ) adj[i].clear();
 
        int n, m;
        cin >> n >> m;
        for ( int i = 1; i <= m; i++ ) {
            int u, v;
            cin >> u >> v;
            adj[u].PB ( v );
            adj[v].PB ( u );
        }
 
        bfs ( 1 );
 
        cout << lev[n] << endl;


 
    }
 
 
 
 
    return 0;
}
