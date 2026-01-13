#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> sgt;
int sizeN;

// Initialize segment tree
// void init(int n) {
//     sizeN = 1;
//     while (sizeN < n) sizeN <<= 1;
//     seg.assign(2 * sizeN, 0);
// }

void update(int i,int l,int r,int idx,int val){
    if(l==r){
        sgt[i]+=val;
        return;
    }
   
    int mid=(l+r)/2;
    if(idx<=mid) update(2*i+1,l,mid,idx,val);
    else update(2*i+2,mid+1,r,idx,val);
  sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}
 
 
int query(int st,int en,int i,int l,int r){
    if(st>r || l>en) return 0;
    if(l>=st && r<=en) return sgt[i];
 
    int mid=(l+r)/2;
    int left=query(st,en,2*i+1,l,mid);
    int right=query(st,en,2*i+2,mid+1,r);
 
    return left+right;
 
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Collect all values for compression
    vector<tuple<char,int,int>> queries(q);
    vector<int> all;

    for (int x : arr) all.push_back(x);

    for (int i = 0; i < q; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        queries[i] = {c, a, b};
        if (c == '?') {
            all.push_back(a);
            all.push_back(b);
        } else {
            all.push_back(b);
        }
    }

    // Coordinate compression
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int cnt = all.size();

    sgt.assign(4 * cnt, 0);
    // Compress initial array and build tree
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(all.begin(), all.end(), arr[i]) - all.begin();
        update(0, 0, cnt - 1, arr[i], 1);
    }

    // Process queries
    for (auto &[t, a, b] : queries) {
        if (t == '!') {
            int idx = a - 1;
            update(0, 0, cnt - 1, arr[idx], -1);
            arr[idx] = lower_bound(all.begin(), all.end(), b) - all.begin();
            update(0, 0, cnt - 1, arr[idx], 1);
        } else {
            int L = lower_bound(all.begin(), all.end(), a) - all.begin();
            int R = upper_bound(all.begin(), all.end(), b) - all.begin() - 1;
            if (L > R) cout << 0 << '\n';
            else cout << query(L, R, 0, 0, cnt - 1) << '\n';
        }
    }

  
}
