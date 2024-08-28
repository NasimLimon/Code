/connected component  grid

const int mx = 1e3 + 10;
char c[mx][mx];
int vis[mx][mx];  // 2D vis array
int n, m, ans = 0;
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] == '.'&&!vis[x1][y1]) {
            dfs(x1, y1);
        }
    }
}

int main() {
    cin >> n >> m;
    
    // Input the grid
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    memset(vis, 0, sizeof(vis));  // Initialize vis array to 0

    // Loop through the grid
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '.'&& !vis[i][j])    {
                dfs(i, j);  // Start DFS
                ans++;  // Increase component count
            }
        }
    }
    
    cout << ans << endl;  // Output the total number of components
    
    return 0;
}
