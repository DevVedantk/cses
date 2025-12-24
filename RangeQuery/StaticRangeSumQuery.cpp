#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
    vector<int>arr(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
    }
    
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << arr[r]-arr[l-1] << endl;
    }
}