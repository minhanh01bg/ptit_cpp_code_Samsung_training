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

#define pb push_back
#define mp make_pair
/*__________________________MY CODE___________________________*/
void Process()
{
    string s;
    cin >> s;
    string s1 = "";
    int check[26];
    rep(i, 0, 25) check[i] = -1;
    rep(i, 0, s.length() - 1)
    {
        check[s[i] - 'a'] = i;
    }

    int k = 25;
    int i = 0;
    while (k >= 0 && i < s.length())
    {
        if (check[k] == -1)
        {
            k--;
            continue;
        }
        while (i <= check[k])
        {
            if (s[i] - 'a' == k)
                s1 = s1 + s[i];
            i++;
        }
        k--;
    }
    cout << s1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Process();
}