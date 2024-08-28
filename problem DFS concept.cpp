//https://vjudge.net/contest/639854#problem/E
const int mx = 1e5 + 10;
vector<int>adj[mx];
bool visited[mx];
int color[mx];
int cnt1 = 0, cnt2 = 0;

void dfs(int node, int col) {
    visited[node] = 1;
    color[node] = col;
    
    if (col == 1) cnt1++;
    else cnt2++;
    int temp;
     if(col==1) temp=2;
     else{
         temp=1;
     }
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, temp);
        }
    }
}

 int32_t main(){

    optimize();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
        color[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    dfs(1, 1);
    long long ans =(long long)  ((cnt1 * cnt2) - (n - 1));

    cout << ans << endl;

    return 0;
