//bipartile check with bfs

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//https://vjudge.net/problem/uva-10004
const int mx = 300;
vector<int> adj[mx];
int col[mx];

bool isBicolor ( int s )
{
    memset(col,-1,sizeof(col));

    col[s] = 1;
    queue<int> q;
    q.push( s );

    while ( !q.empty() ) {
        int u = q.front();
        q.pop();

       

        for ( auto v : adj[u] ) {
            if ( col[v] == -1 ) {
                if ( col[u] == 1 ) col[v] = 2;
               else col[v] = 1;

                q.push( v );
            }
            else if ( col[v] == col[u] ) return 0;
        }
    }

    return 1;
}

int main()
{
    optimize();


    int n;

    while ( cin >> n ) {
        if (  n == 0 ) break;

        for ( int i = 0; i < mx; i++ ) adj[i].clear();

        int m;
        cin >> m;
        for ( int i = 1; i <= m; i++ ) {
            int u, v;
            cin >> u >> v;
            adj[u].PB ( v );
            adj[v].PB ( u );
        }


        if ( isBicolor(0) ) cout << "BICOLORABLE.\n";// 0=starting index
        else cout << "NOT BICOLORABLE.\n";

    }

    return 0;
}

