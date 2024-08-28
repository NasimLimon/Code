
const int mx = 102;
int adjMat[mx][mx]; // adjacancy matrix with 0 and 1.
// char adjMat[mx][mx];//adjacancy grid with .,#,S(starting point) and T(ending
// point).
/*
//undirected graph adjacancylist
const int mx=1e5+123;
vector<int>adjlist[mx];
int n,m;
cin>>n>>m;/ /m=edge
for(int i=1;i<=m;i++){
int u,v;
cin>>u>>v;
adjlist[u].push_back(v);//every cell again act as a new vector.
adjlist[v].push_back(u);
}
for(int i=1;i<=n;i++){
cout<<"adjacancy list"<<i<<":";
for(auto u:adjlist[i]){
cout<<u<<" ";
cout<<endl;
}
}

}



*/
/*
/undirected weighted graph adjacancylist
const int mx=1e5+123;
vector<pair<int,int>adjlist[mx];
int n,m;
cin>>n>>m;
for(int i=1;i<=m;i++){
int u,v,w;
cin>>u>>v>>w;
adjlist[u].push_back({v,w});//create makepair with weight
adjlist[v].push_back({u,w});
}
for(int i=1;i<=n;i++){
cout<<"adjacancy list"<<i<<":";
for(auto u:adjlist[i]){
cout<<u<<"Node: "<<u.first<<"And"<<"cost"<<u.second<<" ";
cout<<endl;
}
}

}



*/
int main() {
    optimize();
    int n; // node
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= n; l++) {
            cin >> adjMat[i][l];
        }
    }
    /*
    for  adjacancy grid
    int n,m;
    cin>>n>>m;//m=edge
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            cin>>adjMat[i][l];
        }
    }*/


    return 0;
