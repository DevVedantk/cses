#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<vector<int>>sgt;

void buildt(int idx, int l, int r, vector<int>& arr) {
    if (l == r) {
        sgt[idx].push_back(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    buildt(2 * idx + 1, l, mid, arr);
    buildt(2 * idx + 2, mid + 1, r, arr);

    // Optimized merging using STL
    sgt[idx].resize(r - l + 1);
    std::merge(sgt[2 * idx + 1].begin(), sgt[2 * idx + 1].end(),
               sgt[2 * idx + 2].begin(), sgt[2 * idx + 2].end(),
               sgt[idx].begin());
}

int query(int st, int en, int val1, int val2, int i, int l, int r) {
    if (st > r || l > en) return 0;
    if (l >= st && r <= en) {
        // Find count of elements in [val1, val2]
        auto it1 = lower_bound(sgt[i].begin(), sgt[i].end(), val1);
        auto it2 = upper_bound(sgt[i].begin(), sgt[i].end(), val2);
        return distance(it1, it2);
    }
    int mid = (l + r) / 2;
    return query(st, en, val1, val2, 2 * i + 1, l, mid) +
           query(st, en, val1, val2, 2 * i + 2, mid + 1, r);
}
signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
    sgt.assign(4*n,vector<int>());
    
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildt(0,0,n-1,arr);
    
    
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
       
       cout << query(a,b,c,d,0,0,n-1) << endl;
           
    }
    
    // cout << "hello";
    
}