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

/*_________________________________MY_CODE_______________________*/

string str;
int k;
const int MN = 1e7 + 1;
int dp[MN];
int number(int x)
{
    int ans = 0;
    while (x)
    {
        ans = x % 10;
        x /= 10;
    }
    return ans;
}
void init()
{
    for (int i = 1; i <= 9; i++)
        dp[i] = 1;

    for (int i = 10; i <= 18; i++)
        dp[i] = dp[i - 1] + 1;

    for (int i = 19; i <= MN; i++)
    {
        int x = number(i);
        dp[i] = dp[i - x] + 1;
    }
    // for(int i=1;i<=50;i++){
    //     cout<<dp[i]<<" "<<i<<endl;
    // }
}

void solve()
{
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= MN; i++)
    {
        if (dp[i] == k)
        {
            ans = i;
        }
        if (dp[i] > k)
            break;
    }
    cout << ans << endl;
}

int main()
{
    fast();
    init();
    run()
    {
        solve();
    }
}