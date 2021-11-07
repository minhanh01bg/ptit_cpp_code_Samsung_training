#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
ll n, m, x, y, z;
vector<pair<ll, ll>> List[200011];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
ll d[100011], dp[100011];

void dijstra()
{
    FOR(i, 1, n)
    d[i] = 1e18;
    d[1] = 0;
    dp[1] = 1;
    Q.push(make_pair(0, 1));
    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        if (u == n)
        {
            cout << d[u] << " " << dp[u];
            return;
        }
        FOR(i, 0, List[u].size() - 1)
        {
            ll v = List[u][i].second;
            ll value = List[u][i].first;
            if (d[v] > d[u] + value)
            {
                d[v] = d[u] + value;
                dp[v] = dp[u];
                Q.push(make_pair(d[v], v));
            }
            else if (d[v] == d[u] + value)
                dp[v] += dp[u];
        }
    }
}

main()
{
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> x >> y >> z;
        List[x].push_back(make_pair(z, y));
        List[y].push_back(make_pair(z, x));
    }
    dijstra();
    return EXIT_SUCCESS;
}