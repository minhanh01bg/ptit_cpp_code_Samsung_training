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
#define read(x) cin >> x
#define readv(x, n) \
    vi x(n);        \
    forn(i, 0, n) cin >> x[i]
#define run()     \
    int TEST;     \
    read(TEST);   \
    cin.ignore(); \
    while (TEST--)
#define ll long long

#define pb push_back
#define mp make_pair
int m, Q;
int a[9001];

void Process()
{
    string s;
    getline(cin, s);
    stack<int> st;
    int d = 0;
    int ans = 0;
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(d);
            d += 1;
        }
        if (s[i] == ')')
        {
            ans = max(ans, d);
            if (!st.empty())
                st.pop();
            else
            {
                x = 1;
                break;
            }
            d -= 1;
        }
    }
    if (!st.empty() || x == 1)
        cout << -1;
    else
        cout << ans;
    cout << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    run()
        Process();
    return 0;
}