/** In the Name of ALLAH */


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);


inline ll gcd ( ll a, ll b ) { return __gcd (a, b); }
inline ll lcm ( ll a, ll b ) { return ( a * ( b / gcd (a, b) ) ); }



#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}



int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

const int mx = 212;
char c[mx][mx];
int n, m;
int levFire[mx][mx], levJan[mx][mx];
vii s;


void bfsFire ()
{
    mem ( levFire, -1 );
    queue<pii> q;

    for ( auto u : s ) {
        q.push ( u );
        levFire[u.F][u.S] = 0;
    }

    while ( !q.empty() ) {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        for ( int i = 0; i < 4; i++ ) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if ( x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] != '#' && levFire[x1][y1] == -1 ) {
                levFire[x1][y1] = levFire[x][y] + 1;
                q.push( { x1, y1 } );
            }
        }
    }

}





void bfsJanVai ( int xs, int ys )
{
    mem ( levJan, -1 );
    queue<pii> q;
    q.push( { xs, ys } );
    levJan[xs][ys] = 0;

    while ( !q.empty() ) {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        for ( int i = 0; i < 4; i++ ) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if ( x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] != '#' && levJan[x1][y1] == -1 && levJan[x][y]+1 < levFire[x1][y1] ){
                levJan[x1][y1] = levJan[x][y] + 1;
                q.push( { x1, y1 } );
            }
        }
    }

}




int main()
{
	optimize();

    int t;
    cin >> t;
    for ( int tc = 1; tc <= t; tc++ ) {
        cin >> n >> m;
        int x, y;

        s.clear();

        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {
                cin >> c[i][j];

                if ( c[i][j] == 'J' ) {
                    x = i, y = j;
                }
                else if ( c[i][j] == 'F' ) {
                    s.PB ( { i, j } );
                }
            }
        }

        bfsFire();
        bfsJanVai( x, y );

        int ans = inf;

        for ( int i = 1; i <= n; i++ ) {
            if ( levJan[i][1] != -1 ) ans = min ( ans, levJan[i][1] );  
        }

        for ( int i = 1; i <= n; i++ ) {
            if ( levJan[i][m] != -1 ) ans = min ( ans, levJan[i][m] );  
        }

        for ( int i = 1; i <= m; i++ ) {
            if ( levJan[1][i] != -1 ) ans = min ( ans, levJan[1][i] );  
        }

        for ( int i = 1; i <= m; i++ ) {
            if ( levJan[n][i] != -1 ) ans = min ( ans, levJan[n][i] );  
        }

        if ( ans == inf ) cout << "Case " << tc << ": IMPOSSIBLE" << endl;
        else cout << "Case " << tc << ": " << ans + 1 << endl;

    }
 
	return 0;
}