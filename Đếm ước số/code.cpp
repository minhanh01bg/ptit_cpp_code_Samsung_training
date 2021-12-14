#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define iip pair<int, int>
#define all(C) C.begin(), C.end()

#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define FOR2(i, a, b) for (ll i = (ll)a; i <= (ll)b; ++i)
#define FORD(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)

#define mod 1e9 + 7
const int NM = 1e3;

using namespace std;
int n, k;
ll x[432];
void Prime(int z)
{
    for (int i = 2; i <= sqrt(z); i++)
    {
        while (z % i == 0)
        {
            x[i] += 1;
            z /= i;
        }
    }
    if (z > 1)
        x[z] += 1;
}
void Prime1(int z)
{
    for (int i = 2; i <= sqrt(z); i++)
    {
        while (z % i == 0)
        {
            x[i] -= 1;
            z /= i;
        }
    }
    if (z > 1)
        x[z] -= 1;
}
void solve()
{
    for (int i = 0; i <= 431; i++)
        x[i] = 0;

    for (int i = 2; i <= n; i++)
        Prime(i);

    for (int i = 2; i <= k; i++)
        Prime1(i);

    for (int i = 2; i <= n - k; i++)
        Prime1(i);

    ll ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= (x[i] + 1);
    if (n >= k)
        cout << ans << endl;
    else
        cout << 1 << endl;
}
signed main()
{
    while (cin >> n >> k)
    {
        // if (k < n / 2)
        // k = n - k;
        solve();
    }
}