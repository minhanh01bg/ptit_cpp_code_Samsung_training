#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define EL printf("\n")
#define sz(A) (int)A.size()
#define ii pair<int, int>
#define iii map<int, int>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

using namespace std;
/*____________________________________MY CODE_______________________________________*/
const int MN = 1e5 + 11;

struct Data
{
    int i, j, k, type, id;
};

Data a[MN*4];

int bit[MN * 4], res[MN * 4];
int n, Query;
//sort giam dan
bool cmp(Data x, Data y)
{
    return (x.k > y.k) or (x.k == y.k and x.type > y.type);
}
// fenwick tree
void update(int x)
{
    int idx = x;
    while (idx <= n)
    {
        bit[idx] += 1;
        idx += (idx & (-idx));
    }
}

int get(int x)
{
    int ans = 0, idx = x;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].k;
        a[i].i = a[i].j = i;
        a[i].type = -1;
    }
    cin >> Query;
    for (int i = 1; i <= Query; i++)
    {
        cin >> a[i + n].i >> a[i + n].j >> a[i + n].k;
        a[i + n].type = 0;
        a[i + n].id = i;
    }
    //sort giam dan
    sort(a + 1, a + n + Query + 1, cmp);
    
    for (int i = 1; i <= n + Query; i++)
    {
        if (a[i].type == -1)
            update(a[i].i);
        else
            res[a[i].id] = get(a[i].j) - get(a[i].i - 1);
    }
    for (int i = 1; i <= Query; i++)
        cout << res[i] << endl;
}