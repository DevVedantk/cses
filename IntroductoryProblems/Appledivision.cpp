#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int>p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    
    int ans=INT_MAX;
    
    for(int i=0;i<(1<<n);i++){
        int g1=0,g2=0;
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0) g1+=p[j];
            else g2+=p[j];
        }
        ans=min(ans,abs(g1-g2));
    }
    
    cout << ans << endl;
}