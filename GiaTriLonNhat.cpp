#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define sz(A) (int)A.size()
#define ii pair<int, int>
#define iii map<int, int>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

using namespace std;
/*____________________________________MY CODE_______________________________________*/
const int MN = 1e5 + 11;

ll ST[MN * 4], add[MN * 4];

void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u || l > r)
        return;
    if (u <= l && r <= v)
    {
        ST[id] += val;
        add[id] += val;
        return;
    }
    update(id * 2, l, (l + r) / 2, u, v, val);
    update(id * 2 + 1, (l + r) / 2 + 1, r, u, v, val);
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]) + add[id];
}

ll get(int id, int l, int r, int u, int v)
{
    if (v < l || u > r || l > r)
        return INT_MIN;
    if (u <= l && r <= v)
        return ST[id];
    return max(get(id * 2, l, (l + r) / 2, u, v), get(id * 2 + 1, (l + r) / 2 + 1, r, u, v)) + add[id];
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen( "input.txt", "r", stdin );
//     freopen( "output.txt", "w", stdout );
// #endif
//     srand(time(NULL));
    int n, m;
    cin >> n >> m;
    int x, y, val;
    FOR(i, 1, m)
    {
        cin >> x >> y >> val;
        update(1, 1, n, x, y, val);
    }

    int Query;
    cin >> Query;
    while (Query--)
    {
        cin >> x >> y;
        cout << get(1, 1, n, x, y) << endl;
    }
}