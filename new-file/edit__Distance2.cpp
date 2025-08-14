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
string s1, s2;
ll dp[5005][5005];
ll Edit_Distance(ll length1, ll length2)
{
    // length1=we have to match/check the length1 amount of length String1;
    // length2=we have to match/check the length1 amount of length String2;
    // dp[length1][length2]= need number of steps to match both string;
    if (length1 == 0)
        return length2;
    if (length2 == 0)
        return length1;
    if (dp[length1][length2] != -1)
        return dp[length1][length2];
    ll ans= 0;                                        

    if (s1[length1 - 1] == s2[length2 - 1])
    {
        return Edit_Distance(length1 - 1, length2 - 1);
    }
    else
    {
        ans = min(Edit_Distance(length1, length2 - 1), Edit_Distance(length1 - 1, length2));
        ans = min(ans, Edit_Distance(length1 - 1, length2 - 1)) + 1;
        dp[length1][length2] = ans;
    }
    return ans;
}
int main()
{
    Limon();

    cin >> s1 >> s2;
    ll n, m;
    memset(dp, -1, sizeof(dp));
    n = s1.size();
    m = s2.size();
    cout << Edit_Distance(n, m) << endl;
}