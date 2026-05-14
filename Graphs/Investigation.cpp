#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;

        adj[a].push_back({b, wt});
    }

    const int INF = 1e18;
    const int MOD = 1e9 + 7;

    vector<int> dist(n + 1, INF);
    vector<int> ways(n + 1, 0);

    vector<int> mn(n + 1, INF);
    vector<int> mx(n + 1, -INF);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[1] = 0;
    ways[1] = 1;

    mn[1] = 0;
    mx[1] = 0;

    pq.push({0,1});

    while(!pq.empty()) {

        auto [dis,node] = pq.top();
        pq.pop();

        if(dis > dist[node]) continue;

        for(auto [child,wt] : adj[node]) {

            if(dist[child] > dis + wt) {

                dist[child] = dis + wt;

                ways[child] = ways[node];

                mn[child] = mn[node] + 1;
                mx[child] = mx[node] + 1;

                pq.push({dist[child], child});
            }

            else if(dist[child] == dis + wt) {

                ways[child] =
                    (ways[child] + ways[node]) % MOD;

                mn[child] =
                    min(mn[child], mn[node] + 1);

                mx[child] =
                    max(mx[child], mx[node] + 1);
            }
        }
    }

    cout << dist[n] << " "
         << ways[n] << " "
         << mn[n] << " "
         << mx[n] << endl;
}