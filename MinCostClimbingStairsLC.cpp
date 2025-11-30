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
int dp[100 + 5];
int a[2] = {1, 2};
int MinCostStair(vector<int> &v, int siz)
{
    if (siz == 0)
        return v[0];
    int mx = 2000000000;
    for (int i = 0; i < 2; i++)
    {
        if (siz - a[i] >= 0)
        {
            mx = min(mx, MinCostStair(v, siz - a[i]));
        }
    }
     dp[siz] = mx;
    return dp[siz];
}
int main()
{
    Limon();
    int n;
    cin >> n;
    vector<int> v1;
for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < 104; i++)
        dp[i] = -1;
    cout << MinCostStair(v1, v1.size() + 1) << endl;
}
