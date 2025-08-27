#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int dp[100001][101];
int MOD=1e9+7;
int solve(vector<int>& arr,int idx,int prev,int m){
    if(idx>=arr.size()) return 1;
    
    
    if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];
    int ans=0;
    // for(int i=idx;i<arr.size();i++){
        if(arr[idx]==0 && prev==-1){
            for(int j=1;j<=m;j++){
                ans=(ans+solve(arr,idx+1,j,m))%MOD;
            } 
        }
        else if(arr[idx]==0 && prev!=-1){
        for(int j=(prev-1<=0 ? 1:prev-1);j<=prev+1 && j<=m;j++){
   if(abs(prev-j)<=1) ans=(ans+solve(arr,idx+1,j,m))%MOD;
            } 
        }
        else{
        if(idx>0 && abs(prev-arr[idx])<=1) ans=(ans+solve(arr,idx+1,arr[idx],m))%MOD;
        else if(idx==0) ans=(ans+solve(arr,idx+1,arr[idx],m))%MOD;
        }
    // }
     if(prev==-1) return ans;
    return dp[idx][prev]=ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    vector<int>arr(n);
     memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    
    int ans=solve(arr,0,-1,m);
    cout << ans << endl;
}