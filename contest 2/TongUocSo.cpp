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
const int MN = 1e6 + 11;

/*_______________________MY CODE______________________*/
ll f[MN];
int a, b;
signed main()
{
    cin >> a >> b;

    for (int i = 2; i <= b; i++)
    {
        for (int j = i * 2; j <= b; j += i)
        {
            f[j] += i;
        }
    }
    
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (f[i] + 1 > i)
        {
            cnt += 1;
        }
    }
    cout << cnt;
}