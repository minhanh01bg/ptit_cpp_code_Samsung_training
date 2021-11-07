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

void Process()
{
    ll a;
    cin >> a;
    vector<ll> C(a);
    for (int i = 0; i < C.size(); i++)
        cin >> C[i];
    vector<ll> l(a, -1), r(a, -1);
    stack<ll> S;

    FOR(i, 0, a - 1)
    {
        while (!S.empty() && C[i] < C[S.top()])
        {
            r[S.top()] = i - 1;
            S.pop();
        }
        S.push(i);
    }
    while (!S.empty())
    {
        r[S.top()] = a - 1;
        S.pop();
    }
    FORD(i, a - 1, 0)
    {
        while (!S.empty() && C[i] < C[S.top()])
        {
            l[S.top()] = i + 1;
            S.pop();
        }
        S.push(i);
    }
    while (!S.empty())
    {
        l[S.top()] = 0;
        S.pop();
    }
    ll mx = 0;
    FOR(i, 0, a - 1)
    {
        mx = max(mx, (r[i] - l[i] + 1) * C[i]);
    }
    cout << mx << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Process();
    return 0;
}