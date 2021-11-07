#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, X, Y, Z;

ll line(ll i, ll a, ll b)
{
    if (i < a)
        return X;
    else if (i >= a && i <= b)
        return Y;
    else if (i > b)
        return Z;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> X >> Y >> Z;
    vector<pair<ll, ll>> a;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll ai, bi;
        cin >> ai >> bi;
        v.push_back(ai);
        v.push_back(bi);
        a.push_back(make_pair(ai, bi));
    }

    ll res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ll sum = 0;
        for (int k = 0; k < n; k++)
        {
            sum += line(v[i], a[k].first, a[k].second);
        }
        res = max(res, sum);
    }
    cout << res;
    return 0;
}
// #include <bits/stdc++.h>

// #define ll long long
// #define ld long double
// #define ull unsigned long long
// #define pb push_back
// #define eb emplace_back
// #define f first
// #define s second
// #define p pair
// #define all(C) C.begin(), C.end()
// #define Begin()   \
//     int N;        \
//     cin >> N;     \
//     cin.ignore(); \
//     while (N--)

// #define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
// #define FOR2(i, a, b) for (ll i = (ll)a; i <= (ll)b; ++i)
// #define FORD(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)

// // Get values

// #define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
// #define minOf(C) min_element(C.begin(), C.end()) - C.begin()

// // Clear containers

// #define reset(C) memset(C, 0, sizeof(C))
// #define Fill(C, a) fill(C.begin(), C.end(), a)

// // Customize containers

// #define SORT(C) sort(C.begin(), C.end())
// #define SORTD(C, x) sort(C.begin(), C.end(), greater<x>())
// #define SORTC(C, check) sort(C.begin(), C.end(), check)
// #define tlw(C)                                           \
//     for (int i = 0; i < (sizeof(C) / sizeof(C[0])); i++) \
//     C[i] = tolower(C[i])
// #define tup(C)                                           \
//     for (int i = 0; i < (sizeof(C) / sizeof(C[0])); i++) \
//     C[i] = toupper(C[i])
// #define Merge(C, F, K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
// #define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
// #define CutInHalf(C, F, x, y)                      \
//     y<x> F(C.begin() + C.size() / 2 + 1, C.end()); \
//     C.resize(C.size() / 2)
// #define revrs(C) reverse(C.begin(), C.end())

// // Scan and print containers

// #define getVector(C)                  \
//     for (ll _ = 0; _ < C.size(); _++) \
//     cin >> C[_]
// #define printVector(C)                 \
//     for (int _ = 0; _ < C.size(); _++) \
//     cout << C[_] << ' '

// // Containers

// #define vec(x) vector<x>
// #define Matrix(x) vector<vector<x>>
// #define Rubik(x) vector<vector<vector<x>>>
// #define pq(x) priority_queue<x>
// #define reverse_pq(x) priority_queue<x, vector<x>, greater<x>>
// #define ordered_set(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_multiset(T) tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>

// // System

// #define faster()                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(0);                       \
//     cout.tie(0);

// // Namespaces

// using namespace std;

// bool cmp(p<ll, ll> A, p<ll, ll> B)
// {
//     if (A.s == B.s)
//         return A.f < B.f;
//     return A.s < B.s;
// }

// map<ll, ll> CONVERT;

// set<ll> M;

// ll BIT[500005];

// const ll N = 500005;

// void updatePoint(ll idx, ll num)
// {
//     while (idx <= N)
//     {
//         BIT[idx] += num;
//         idx += idx & (-idx);
//     }
// }

// void update(ll l, ll r, ll num)
// {
//     updatePoint(l, num);
//     updatePoint(r + 1, -num);
// }

// ll get(ll idx)
// {
//     ll t = 0;
//     while (idx)
//     {
//         t += BIT[idx];
//         idx -= idx & (-idx);
//     }
//     return t;
// }

// void Process()
// {
//     reset(BIT);
//     ll a, x, y, z;
//     cin >> a >> x >> y >> z;
//     vector<p<ll, ll>> C(a);
//     for (auto &x : C)
//     {
//         cin >> x.f >> x.s;
//         M.insert(x.f);
//         M.insert(x.s);
//     }
//     ll t = 1;
//     for (auto x : M)
//     {
//         CONVERT[x] = t;
//         t++;
//     }
//     for (auto &x : C)
//     {
//         x.f = CONVERT[x.f];
//         x.s = CONVERT[x.s];
//         update(x.f, x.s, 1);
//     }
//     SORT(C);
//     ll ans = -1;
//     p<ll, ll> tmp;
//     tmp.s = 0;
//     FOR(i, 1, 500000)
//     {
//         ll mx = get(i);
//         ll pre, in, suf;
//         in = mx;
//         tmp.f = i + 1;
//         ll k = lower_bound(all(C), tmp) - C.begin();
//         pre = C.size() - k;
//         suf = C.size() - in - pre;
//         ans = max(ans, pre * x + in * y + suf * z);
//     }
//     cout << ans << endl;
// }

// signed main()
// {
//     faster();
//     Process();
// }
