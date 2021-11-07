#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int x = 1e5 + 11;
const int mod = 1e9 + 7;
ll fac[x], ifac[x];
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = power(a, b / 2) % mod;
    return (b & 1) ? ((t * t) % mod) * a % mod : (t * t) % mod;
}

void init()
{
    fac[1] = ifac[1] = 1;
    FOR(i, 2, 100000)
    fac[i] = (i * fac[i - 1]) % mod;
    ll p = 1e9 + 7 - 2;
    ifac[100000] = power(fac[100000], p);

    for (int i = 99999; i >= 2; i--)
        ifac[i] = ((i + 1) * ifac[i + 1]) % mod;
}

ll C(int n, int r)
{
    if (n < r)
        return 0;
    return (((fac[n] * ifac[n - r]) % mod) * ifac[r]) % mod;
}

ll P(int n, int k)
{
    if (k > n)
        return 0;
    return (fac[n] * ifac[n - k]) % mod;
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        // cout << C(n, r) << endl;
        cout << P(n, r) << endl;
        // cout << fac[n] << " " << ifac[n - r] << " " << ifac[r] << endl;
    }
    return 0;
}