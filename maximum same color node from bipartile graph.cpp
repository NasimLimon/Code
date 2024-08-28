//find  maximum same color node from bipartile graph


const int mx = 2e4+123;
bool vis[mx];
vi adj[mx];
bool isNode[mx];
int cnt, cnt1;

void dfs ( int u, int col )
{
    vis[u] = 1;
    if ( col == 1 ) cnt1++;
    cnt++;

    int tmp;
    if ( col == 1 ) tmp = 2;
    else tmp = 1;

    for ( auto v : adj[u] ) {
        if (  vis[v] == 0 ) {
        dfs ( v, temp );
        }
    }
}


int main()
{
    optimize();

    int T;
    cin >> T;
    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i < mx; i++ ) {
            adj[i].clear();
            isNode[i] = 0;
            vis[i] = 0;
        }

        int m;
        cin >> m;
        for ( int i = 1; i <= m; i++ ) {
            int u, v;
            cin >> u >> v;
            adj[u].PB ( v );
            adj[v].PB ( u );

            isNode[u] = 1;
            isNode[v] = 1;
        }

        int ans = 0;
        for ( int i = 1; i <= 2e4; i++ ) {
            if ( isNode[i] == 1 && vis[i] == 0 ) {
                cnt = 0, cnt1 = 0;
                dfs ( i, 1 );
                ans += max ( cnt1, cnt - cnt1 );
            }
        }

        cout << "Case " << tc << ": " << ans << endl;
    }


    return 0;
}