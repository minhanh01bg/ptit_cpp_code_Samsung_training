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
const int MN = 5e4 + 11;

using namespace std;
/*____________________________________MY CODE_______________________________________*/
int dp[26];
char S[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
void init()
{
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= 25; i++)
        dp[i] = dp[i - 1] * 2 + 1;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k & 1)
    {
        cout << 'A' << endl;
        return;
    }
    for (int i = 2; i <= 25; i++)
    {
        int x = dp[i - 1] + 1, y = dp[i] + 1;
        if ((k - x) % y == 0)
        {
            cout << S[i] << endl;
            return;
        }
    }
}

int main()
{
    init();
    run()
        solve();
    return 0;
}