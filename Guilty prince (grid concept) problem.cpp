const int mx = 23;
char c[mx][mx];
int n, m, cnt;
bool vis[mx][mx];

int dx[] = { -1, +1, 0, 0 };//left,right,up,down
int dy[] = { 0, 0, +1, -1 };

void dfs ( int x, int y )
{
    vis[x][y] = 1;
    cnt++;

    for ( int i = 0;i< 4; i++ ) {//Explore its four neighboring cells one by one (left, right, up, down).
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if ( x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] == '.' && vis[x1][y1] == 0 ) {
            dfs ( x1, y1 );
        }
    }
}



int main()
{
    optimize();
    int T;
    cin >> T;

    for ( int tc = 1; tc <= T; tc++ ) {
        cin >> n >> m;
        swap ( n, m );
        int x, y;

        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {
                cin >> c[i][j];

                if ( c[i][j] == '@' ) {//starting point
                    x = i;
                    y = j;
                }
            }
        }

        memset(vis,0,sizeof(vis));
        cnt = 0;
        dfs ( x, y );

        cout << "Case " << tc << ": " << cnt << endl;
    }




    return 0;
}