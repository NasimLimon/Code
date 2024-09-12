// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
struct info {
    int u, v, w;
};

const int mx = 1e3+123;
vector<info> e;
long long dist[mx];

bool belmanFord ( int s, int n, int m )
{
    for ( int i = 0; i < n; i++ ) dist[i] = LLONG_MAX;
    dist[s] = 0;

    bool isCycle;

    for ( int i = 1; i <= n; i++ ) {
        isCycle = false;

        for ( int j = 0; j < m; j++ ) {
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;

            if ( dist[u] < LLONG_MAX ) {
                if ( dist[u] + w < dist[v] ) {
                    dist[v] = max ( -LLONG_MAX, dist[u] + w );
                    isCycle = true;
                }
            }
        }
    }

    return isCycle;
}


int main()
{
	optimize();

	int t;
	cin >> t;

	while ( t-- ) {
	    e.clear();
	    int n, m;
	    cin >> n >> m;

	    for ( int i = 0; i < m; i++ ) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        e.push_back ( { u, v, w } );
	    }

	    if ( belmanFord ( 0, n, m ) == true ) {
	        cout << "possible\n";
	    }

	    else {
	        cout << "not possible\n";
	    }
	}


	return 0;
}