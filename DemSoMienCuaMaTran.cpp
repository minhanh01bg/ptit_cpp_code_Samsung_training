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

int m, n;
int a[101][101];
/*
2
3 3
1 1 0
0 0 1
1 0 1
4 4
1 1 0 0
0 0 1 0
0 0 0 1
0 1 0 0
*/
int dX[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int dY[8] = {1, 0, -1, 0, 1, -1, 1, -1};
bool check[101][101];
void init()
{
    rep(i, 0, m - 1)
        rep(j, 0, n - 1)
            check[i][j] = false;
}
bool survey(int x, int y)
{
    if (x < 0 || y < 0 || x >= m || y >= n || a[x][y] == 0)
        return false;
    return true;
}
void bfs(int i, int j)
{
    queue<pi> Q;
    Q.push({i, j});
    while (!Q.empty())
    {
        pi x = Q.front();
        Q.pop();
        rep(k, 0, 7)
        {
            int u = x.first + dX[k];
            int v = x.second + dY[k];
            if (survey(u, v) && !check[u][v])
            {
                check[u][v] = true;
                Q.push({u, v});
            }
        }
    }
}
void Process()
{
    read(m), read(n);
    init();
    rep(i, 0, m - 1)
    {
        rep(j, 0, n - 1) { read(a[i][j]); }
    }
    int cnt = 0;
    rep(i, 0, m - 1)
    {
        rep(j, 0, n - 1)
        {
            if (check[i][j] == false && a[i][j] == 1)
            {
                cnt += 1;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    run()
        Process();
}