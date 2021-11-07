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

signed main()
{
    fast();
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == 0)
        {
            cout << x << " ";
            x = 1;
        }
        else
        {
            cout << x << " ";
            x = 0;
        }
    }
    cout << endl;
    x = 1;
    for (int i = 0; i < n; i++)
    {
        if (x == 0)
        {
            cout << x << " ";
            x = 1;
        }
        else
        {
            cout << x << " ";
            x = 0;
        }
    }
}