// Recursive Approach
ll BinaryExpo(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = BinaryExpo(a, b / 2);
    if (b % 2 != 0)
    {
        return (a * (res * res) % MOD) % MOD;
    }
    else
    {
        return ((res * res) % MOD) % MOD;
    }
}
int main()
{
    optimize();
    ll n, m;
    cin >> n >> m;
    cout << BinaryExpo(n, m) << endl;
}

