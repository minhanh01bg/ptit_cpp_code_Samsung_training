#include <bits/stdc++.h>
// #include<math.h>
// #include<iostream>
// #include<map>
// #include<pair>
// #include<vector>
// #include<algorithm>
// #include<set>

#define ll long long
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
signed main()
{
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += abs(a[i]);
    }
    ll sum = 0, best = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(a[i], sum + a[i]);
        best = max(sum, best);
    }
    cout << best;
}
// bool cmp(ii a, ii b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
//     return a.first < b.first;
// }
// signed main()
// {
//     int n;
//     cin >> n;
//     ll a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     ll b[n];
//     b[0] = abs(a[0]);
//     for (int i = 1; i < n; i++)
//         b[i] = abs(a[i]) + b[i - 1];

//     ll c[n];
//     c[0] = a[0];

//     for (int i = 1; i < n; i++)
//         c[i] = a[i] + c[i - 1];

//     pair<ll, int> d[n];
//     d[0].first = b[0] + c[0];
//     for (int i = 1; i < n; i++)
//     {
//         d[i].first = b[i] + c[i];
//         d[i].second = i;
//     }
//     sort(d, d + n, cmp);
//     ll ans = -1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (d[i].second >= d[j].second && d[i].first >= d[j].first)
//             {
//                 ans = max(ans, d[i].first - d[j].first + b[d[j].second] + c[d[j].second]);
//                 break;
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }