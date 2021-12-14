// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <ctype.h>
// #include <deque>
// #include <cstring>
// #include <set>
// #include <bitset>
// #include <map>
// #include <chrono>
// #include <random>
// #include <unordered_map>
// #include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(), (c).end()
#define srt(c) sort(all(c))
#define srtrev(c) \
    sort(all(c)); \
    reverse(all(c))
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, a, b) for (int i = a; i < b; i++)
#define read(x) cin >> x
#define readv(x, n) \
    vi x(n);        \
    forn(i, 0, n) cin >> x[i]
#define run()     \
    int TEST;     \
    read(TEST);   \
    cin.ignore(); \
    while (TEST--)
// #define ll long long

#define pb push_back
#define mp make_pair

const int MN = 1e4 + 11;

void Query(int n, int m, ll a[], ll f[])
{
    ll k;
    while (m--)
    {
        read(k);
        ll l = 1, r = lower_bound(f + 1, f + 1 + n, k) - f;

        if (f[r] > k)
            r--;
        // mảng trượt ^.^
        ll cnt = f[r];
        while (cnt + a[r] - a[l - 1] <= k && r <= n)
        {
            cnt += a[r];
            cnt -= a[l - 1];
            l++;
            r++;
        }
        cout << r - l + 1 << " " << a[l - 1] << "\n";
    }
}

void Process()
{
    int n, m;
    cin >> n >> m;
    ll a[n], f[n + 1];
    rep(i, 0, n - 1)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    f[1] = a[0];
    rep(i, 2, n)
        f[i] = f[i - 1] + a[i - 1];
    Query(n, m, a, f);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Process();
    return 0;
}