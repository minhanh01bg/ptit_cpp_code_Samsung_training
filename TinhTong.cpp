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
#define N 300005

using namespace std;
/*____________________________________MY CODE__________________________________*/
string s = "";
int k, B, M;
ll dp[N];
int S[N];
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    ll t = power(a, b / 2) % M;
    return (b & 1) ? ((t * t) % M) * a % M : (t * t) % M;
}

void solve()
{
    cin >> s;
    cin >> k >> B >> M;
    int x = 0, y = k - 1;
    int n = s.length();
    for (int i = 0; i < n; i++)
        S[i] = s[i] - '0';
    
    for (int i = 0; i < k; i++)
        dp[i] = (S[i] * power(B, y--)) % M;

    for (int i = 0; i < k; i++)
    {
        x += dp[i];
        x %= M;
    }
    int ans = x;
    int cnt = 0;
    for (int i = k; i < n; i++)
    {
        x = (((x - (S[cnt] * power(B, k - 1) % M) + M) % M) * B % M + S[i]) % M;
        // cout << x << endl;
        cnt += 1;
        ans += x;
    }
    cout << ans;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    solve();
}