#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    
    vector<vector<int>>arr(n+1,vector<int>(n+1,0));
    vector<vector<int>>pref(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin >> c;
            if(c=='*') arr[i][j]=1;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
     pref[i][j]=arr[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }
    
    for(int i=0;i<q;i++){
        int a,b,c,d;
cin >> a >> b >> c >> d;
 cout << pref[c][d]-pref[a-1][d]-pref[c][b-1]+pref[a-1][b-1] << endl;
    }
    
    
}