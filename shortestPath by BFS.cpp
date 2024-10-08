//find shortest path with bfs

//https://vjudge.net/problem/HackerRank-bfsshortreach
#define pb push_back

using namespace std;

vector<int>adj[1009];

int main() 

{
    
int t,n,m,x,y,s,i;
cin>>t;
while(t--)
{
    cin>>n>>m;
    for(i=0;i<n+3;i++)
    adj[i].clear();
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cin>>s;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    int dist[n+1];
    memset(dist,0,sizeof(dist));
    list<int>q;
    q.push_back(s);
    vis[s]=true;
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop_front();
        for(i=0;i<adj[u].size();i++)
        {
            int v= adj[u][i];
            if(!vis[v])
            {
                vis[v]=true;
                dist[v]=dist[u]+6;
                q.push_back(v);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i!=s)
        {
            if(dist[i]==0)
            cout<<"-1 ";
            else
            cout<<dist[i]<<" ";
        }
    }
    cout<<endl;
}
return 0;
