#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;

int steps(int a,int b,vector<vector<int>>& dp){
    if(a==b) return 0;
    
    //invalid
    if(a<0 || b<0) return INT_MAX;
    
    if(dp[a][b]!=-1) return dp[a][b];
    
    int hori=1e7,verti=1e7;
    
     //vertical cuts
    for(int k=1;k<b;k++){
        verti=min(verti,1+steps(a,k,dp)+steps(a,b-k,dp));
    }

    //horizontal cuts
    for(int k=1;k<a;k++){
        hori=min(hori,1+steps(k,b,dp)+steps(a-k,b,dp));
    }
    
    return dp[a][b]=min(hori,verti);

}

signed main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      
      int a,b;
      cin >> a >> b;
      vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
      int ans=steps(a,b,dp);
      cout << ans << endl;
}


