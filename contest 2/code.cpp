#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define ii pair<int, int>
#define int ll
typedef long long ll;
const int N = 101;
const int INF = 1e9;

int n, m, k, d[N][N], T[N][N];
vector<ii> adj[N];

// void truyvet(int u, int v) {
// 	vector<int> last;
// 	while (v != u) {
// 		last.push_back(v);
// 		v = T[u][v];
// 	}
// 	last.push_back(u);
// 	cout << last.size() << " ";
// 	reverse(last.begin(), last.end());
// 	for (auto v : last)
// 			cout << v << " ";
// 	cout << "\n";
// }

void dijkstra(int k)
{
    for (int i = 1; i <= n; i++)
        d[k][i] = INF;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[k][k] = 0;
    pq.push({0, k});

    while (pq.size())
    {
        int du = pq.top().f;
        int u = pq.top().s;
        pq.pop();
        if (du != d[k][u])
            continue;

        for (auto v : adj[u])
        {
            if (d[k][v.s] > du + v.f)
            {
                d[k][v.s] = du + v.f;
                pq.push({d[k][v.s], v.s});
                T[k][v.s] = u;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    cin >> k;
    int x, u, v;
    while (k--)
    {
        cin >> u >> v;
        // x = 0;
        // if (x == 0)
        // {
            cout << d[u][v] << "\n";
            // continue;
        // }
        // truyvet(u, v);
    }
    return 0;
}