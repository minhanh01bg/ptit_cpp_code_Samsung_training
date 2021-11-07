#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

/*____________________________________MY CODE______________________________*/

const int N = 1e5 + 11;
long long ST[N * 4], add[N * 4];
int n, k;
//Lazy Propagation
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

long long get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u || l > r)
        return INT_MIN;
    if (u <= l && r <= v)
        return ST[id];

    return max(get(id * 2, l, (l + r) / 2, u, v), get(id * 2 + 1, (l + r) / 2 + 1, r, u, v)) + add[id];
}

signed main()
{
    cin >> n >> k;
    while (k--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y, z, val;
            cin >> y >> z >> val;
            update(1, 1, n, y, z, val);
        }
        if (x == 2)
        {
            int y, z;
            cin >> y >> z;
            cout << get(1, 1, n, y, z) << endl;
        }
    }
    return 0;
}