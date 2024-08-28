//grid problem like a find same color from bipartile graph
//https://www.spoj.com/problems/KOZE/
const int mx=2e2+55;
char c[mx][mx];
bool vis[mx][mx];
int k,v;    int n,m;

int dx[]={-1,+1,0,0};
int dy[]={0,0,+1,-1};
int sheep=0,wolves=0;
void dfs(int x,int y){
    vis[x][y]=1;
    if(c[x][y]=='k') k++;
    if(c[x][y]=='v') v++;
    for(int i=0;i<4;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1 && x1<=n && y1>=1 && y1<=m && c[x1][y1]!='#'&& !vis[x1][y1]){
            dfs(x1,y1);
        }

    }
}
int main(){

    optimize();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
            if(c[i][j]=='k') sheep++;
            if(c[i][j]=='v') wolves++;
        }
    }
    memset(vis,0,sizeof(vis));
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if((c[i][j]=='#' || c[i][j]=='.' || c[i][j]=='v'||c[i][j]=='k') && (vis[i][j]==0)){
                k=0,v=0;
                dfs(i,j);
                if(k>v) wolves=wolves-v;
                else sheep=sheep-k;
            }
        }
    
}
cout<<sheep<<" "<<wolves<<endl;
    return 0;
}