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
    vector<ll> dp;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        auto indexPointer = lower_bound(dp.begin(), dp.end(), x);
        if (indexPointer == dp.end())
        {
            dp.push_back(x);
        }
        else
        {
            *indexPointer = x;
        }
    }
    cout << dp.size() << endl;
}