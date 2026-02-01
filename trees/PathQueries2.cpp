#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> sizes, heavy, parent, depth, head, lt, pos;
vector<int> value, sgt;
int idx = 0;
int n;


void dfs(int node, int par, vector<vector<int>>& adj) {
    parent[node] = par;
    sizes[node] = 1;

    for (int child : adj[node]) {
        if (child == par) continue;

        depth[child] = depth[node] + 1;
        dfs(child, node, adj);

        sizes[node] += sizes[child];

        if (heavy[node] == -1 || sizes[child] > sizes[heavy[node]])
            heavy[node] = child;
    }
}

// hld function
void dfsHLD(int node, int par, int chain, vector<vector<int>>& adj) {
    head[node] = chain;
    pos[node] = idx;
    lt[idx] = value[node];
    idx++;

    if (heavy[node] != -1)
        dfsHLD(heavy[node], node, chain, adj);

    for (int child : adj[node]) {
        if (child == par || child == heavy[node]) continue;
        dfsHLD(child, node, child, adj);
    }
}


void buildt(int i, int l, int r) {
    if (l == r) {
        sgt[i] = lt[l];
        return;
    }

    int mid = (l + r) / 2;
    buildt(2*i+1, l, mid);
    buildt(2*i+2, mid+1, r);

    sgt[i] = max(sgt[2*i+1],sgt[2*i+2]);
}

void update(int i, int l, int r, int idx, int val) {
    if (l == r) {
        sgt[i] = val;
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
        update(2*i+1, l, mid, idx, val);
    else
        update(2*i+2, mid+1, r, idx, val);

     sgt[i] = max(sgt[2*i+1],sgt[2*i+2]);
}

int query(int st, int en, int i, int l, int r) {
    if (st > r || en < l) return 0;
    if (st <= l && r <= en) return sgt[i];

    int mid = (l + r) / 2;
    return max(query(st, en, 2*i+1, l, mid),
           query(st, en, 2*i+2, mid+1, r));
}


int queryPath(int a, int b) {
    int res = 0;

    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]])
            swap(a, b);

        int start = head[a];
        res = max(res,query(pos[start], pos[a], 0, 0, n-1));

        a = parent[start];
    }

    if (depth[a] < depth[b]) swap(a, b);

    res = max(res,query(pos[b], pos[a], 0, 0, n-1));
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;

    vector<vector<int>> adj(n);

    value.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;               // convert to 0-based
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sizes.assign(n, 0);
    heavy.assign(n, -1);
    parent.assign(n, -1);
    depth.assign(n, 0);

    dfs(0, -1, adj);

    head.assign(n, 0);
    lt.assign(n, 0);
    pos.assign(n, 0);

    dfsHLD(0, -1, 0, adj);

    sgt.assign(4*n, 0);
    buildt(0, 0, n-1);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int node, val;
            cin >> node >> val;
            node--;
            update(0, 0, n-1, pos[node], val);
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << queryPath(a, b) << " ";
        }
    }
}
