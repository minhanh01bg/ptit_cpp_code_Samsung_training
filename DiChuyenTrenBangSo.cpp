#include <bits/stdc++.h>
// #include<math.h>
// #include<iostream>
// #include<map>
// #include<pair>
// #include<vector>
// #include<algorithm>
// #include<set>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define ii pair<int, int>
#define iii map<int, int>

#define sz(A) (int)A.size()
#define all(c) (c).begin(), (c).end()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

#define run()     \
    int tests;    \
    cin >> tests; \
    cin.ignore(); \
    while (tests--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cout.tie(0);                      \
    cin.tie(0);
#define debug(a)     \
    FOR(i, 0, n - 1) \
    cout << a[i] << " \n"[i == n - 1];

#define INF 1000000000
#define N 10005
using namespace std;
/*_________________MY CODE________________*/
const int MN = 1e3;
int n, m;
int dX[4] = {0, -1, 0, 1}, dY[4] = {-1, 0, 1, 0};
int a[MN][MN], dp[MN][MN];

bool survey(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    return true;
}

void solve()
{
    queue<ii> Q;
    ii S = {1, 1};
    dp[1][1] = a[1][1];
    Q.push(S);
    int ans = 0;
    while (!Q.empty())
    {
        ii x = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int j = x.fi + dX[i], k = x.se + dY[i];
            if (!survey(j, k))
                continue;
            if (dp[j][k] > dp[x.fi][x.se] + a[j][k])
            {
                dp[j][k] = dp[x.fi][x.se] + a[j][k];
                Q.push({j, k});
            }
        }
    }
    cout << dp[n][m] << endl;
}

signed main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    fast();
    run()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                dp[i][j] = INF;
            }
        }
        solve();
    }
    return 0;
}