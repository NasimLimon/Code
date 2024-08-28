//application of dijkstra algorithm in Grid
#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,+1,0,0};
int dy[]={0,0,+1,-1};
const int mx=1e3+10;
int grid[mx][mx];
long long dist[mx][mx];
int node;
void dijkstra(int s,int t){
    dist[s][t]=grid[s][t];
    priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> pq;
    pq.push({grid[s][t],{s,t}});
    while(!pq.empty()){
        long long curD=pq.top().first;
        int x=(pq.top().second).first;
        int y=(pq.top().second).second;
        pq.pop();
        if(curD>dist[x][y]) continue;
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>=1 && x1<=node && y1>=1 && y1<=node && curD+grid[x1][y1]<dist[x1][y1]){
                dist[x1][y1]=curD+grid[x1][y1];
                pq.push({dist[x1][y1],{x1,y1}});
            }
        }
    }
    cout<<dist[node][node]<<endl;
}
int main()
{ 
   cin>>node;
   for(int i=1;i<=node;i++){
       for(int j=1;j<=node;j++){
           cin>>grid[i][j];
           dist[i][j]=1e10;

       }
   }
   dijkstra(1,1);
    
    
    
    return 0;
}
/*
4
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
Out:43
*/