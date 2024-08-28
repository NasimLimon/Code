///print shortest path with bfs
const int mx = 1e5+123;
vector<int> adj[mx];
int lev[mx];
int par[mx];

void bfs ( int s )
{
    mem ( lev, -1 );

    queue<int> q;
    q.push( s );
    lev[s]= 0;

    while ( !q.empty() ) {
        int u = q.front();
        q.pop();

        for ( auto v : adj[u] ) {
            if ( lev[v] == -1 ) {
                lev[v] = lev[u] + 1;
                par[v] = u;
                q.push( v );
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
        int u, v;
        cin >> u >> v;
        adj[u].PB ( v );
        adj[v].PB ( u );
    }

    int s,t;
    cin>>s>>t;
    bfs (s);

    if ( lev[s] == -1 ) {
        cout << "No route\n";
        return 0;
    }

    vector<int> path;
    par[s] = -1;//first node have no parent node for that intial node reserve -1

    while ( t!=-1 ) {
        path.push_back ( t );
        t = par[t];//updating  parent node
    }

    reverse( path.begin(), path.end() );

    for ( auto u : path ) cout << u << " ";
    cout << endl;

    return 0;
}
