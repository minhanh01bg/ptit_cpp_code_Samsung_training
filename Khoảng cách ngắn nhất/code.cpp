#include <bits/stdc++.h>

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
const int MN = 5e6 + 11;
int n, m;
int c1, c2;
int c[MN], d[MN];
void search()
{
    int MIN = INT_MAX, cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(c[i] - d[j]) < MIN)
            MIN = abs(c[i] - d[j]), cnt = 0;
        if (abs(c[i] - d[j]) == MIN)
            cnt++;
        if (abs(c[i] < d[j]))
        {
            i++;
        }
        else
            j++;
    }
    ll ans = MIN + abs(c1 - c2);
    cout << ans << " " << cnt;
}
/* 
INPUT:
3 4
1 -3
3 0 6
-2 5 4 2 
OUTPUT:
5 3
 */
void solve()
{
    cin >> n >> m >> c1 >> c2;

    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> d[i];
    sort(c, c + n);
    sort(d, d + m);

    search();
}
signed main()
{
    solve();
    return 0;
}