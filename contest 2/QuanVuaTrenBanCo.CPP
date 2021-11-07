#include <bits/stdc++.h>

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

int dX[8] = {0, -1, 0, 1, -1, 1, -1, 1};
int dY[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int a, b, c, d;
int dp[10][10];
bool survey(int i, int j)
{
	if (i < 1 || j < 1 || i > 8 || j > 8)
	{
		return false;
	}
	return true;
}
int duong()
{
	queue<ii> Q;
	Q.push({a, b});
	dp[a][b] = 1;
	while (!Q.empty())
	{
		ii x = Q.front();
		Q.pop();
		for (int i = 0; i < 8; i++)
		{
			int x1 = x.first + dX[i];
			int y1 = x.second + dY[i];
			if (!survey(x1, y1))
				continue;
			if (x1 == c && y1 == d)
			{
				dp[c][d] = dp[x.first][x.second];
				return dp[c][d];
			}
			if (!dp[x1][y1])
			{
				dp[x1][y1] = dp[x.first][x.second] + 1;
				Q.push({x1, y1});
			}
		}
	}
	return 0;
}
void solve()
{
	cin >> a >> b >> c >> d;
	cout << duong() << ' ';
}

main()
{
	solve();
	return 0;
}