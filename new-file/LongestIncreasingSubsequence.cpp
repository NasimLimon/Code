//                                           IN THE NAME OF SUPREME & MERCIFUL GOD
//                                               Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
#define Limon()                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main()
{
    Limon();
    ll n;
    cin >> n;
    vector<ll> v1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v1.push_back(x);
    }
    ll length[n];
    for(int i=0;i<n;i++){
        length[i]=1;
    }
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v1[i] > v1[j])
            {
                length[i] = max(length[i], length[j] + 1);

                ans = max(ans, length[i]);
            }
            
        }
    }
    cout << ans << endl;
}