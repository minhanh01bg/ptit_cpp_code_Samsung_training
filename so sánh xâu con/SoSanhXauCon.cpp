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
const int MN = 5e4 + 11;

/*_______________________MY CODE______________________*/

int dp[26][MN];
string s = "";
int n;
void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 25; j++)
            if (s[i] - '0' - 49 == j)
                dp[j][i] = dp[j][i - 1] + 1;
            else
                dp[j][i] = dp[j][i - 1];

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
}

void solve()
{
    cin >> s;
    n = s.length();
    s = " " + s;

    init();
    int quest;
    cin >> quest;
    int a, b, c, d;
    while (quest--)
    {
        cin >> a >> b >> c >> d;
        bool survey = false;
        for (int i = 0; i < 26; i++)
        {
            int x = dp[i][b] - dp[i][a - 1];
            int y = dp[i][d] - dp[i][c - 1];
            if (x != y)
            {
                survey = true;
                break;
            }
        }
        if (survey)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    fast();
    solve();
}