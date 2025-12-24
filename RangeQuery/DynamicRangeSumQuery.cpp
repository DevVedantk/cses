#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

vector<int> fen;

void update(int idx, int val, int n) {
    while (idx <= n) {
        fen[idx] += val;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int s = 0;
    while (idx > 0) {
        s += fen[idx];
        idx -= (idx & -idx);
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    fen.assign(n + 1, 0);
    vector<int>arr(n+1,0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i]=x;
        update(i, x, n);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            int diff=b-arr[a];
             arr[a]=b;  
            update(a, diff, n);      
        } else {
            cout << sum(b) - sum(a - 1) << endl;
        }
    }
}
