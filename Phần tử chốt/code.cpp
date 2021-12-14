#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define p pair
#define all(C) C.begin(), C.end()

#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define FOR2(i, a, b) for (ll i = (ll)a; i <= (ll)b; ++i)
#define FORD(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)

using namespace std;
const int mod = 1e9 + 7;
const int NM = 1e5 + 11;
int n, a[NM];

void process()
{
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    ll dpA[n], dpB[n];
    dpA[0] = a[0];
    dpB[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        dpA[i] = dpA[i - 1] + a[i];
        dpB[i] = dpB[i - 1] + b[i];
    }
    int ans = 0;
    int X[n];
    int MIN = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] == b[i + 1])
            continue;
        if (MIN < a[i])
            MIN = a[i];
        if (MIN > a[i])
            continue;
        if (dpA[i] - a[i] > dpB[i] - b[i])
            continue;
        if (dpA[i] - a[i] == dpB[i] - b[i] && dpA[i] == dpB[i])
            X[ans++] = i;
    }

    if (b[n - 1] == a[n - 1])
        ans += 1;
    cout << ans << endl;
    // for (int i = 0; i < ans; i++)
    // cout << X[i] << " ";
    // cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        process();
}