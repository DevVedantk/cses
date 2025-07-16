#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int>arr(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        arr[i] += arr[i-1]; // prefix sum
    }
    
     set<pair<int,int>>st;
    for(int i=a;i<=a+(b-a);i++) st.insert({arr[i],i});
    
    int maxsum=LLONG_MIN;
    
    for(int i=1;i<=n;i++){
        if (!st.empty()) {
            auto it=st.rbegin();
            maxsum = max(maxsum, it->first - arr[i-1]);
        }

        if(i + a - 1 <= n) st.erase({arr[i+a-1], i+a-1});
        if(i + b <= n) st.insert({arr[i+b], i+b});
    }

    cout << maxsum << endl;
}
