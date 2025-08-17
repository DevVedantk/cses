#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


int MOD=1e9+7;
int dp[100001];
int solve(vector<int>& arr,int idx,int prevTaken){

    if(idx>=arr.size() && prevTaken>0) return 1;
    if(idx>=arr.size() && prevTaken==0) return 0;
    
    if(dp[idx]!=-1) return dp[idx];
    int take=0;
     if(prevTaken<arr[idx]) take=solve(arr,idx+1,arr[idx])%MOD;
    int skip=solve(arr,idx+1,prevTaken)%MOD;
    return dp[idx]=(take+skip)%MOD;
}

signed main(){
   
   int n;
   cin >> n;
    memset(dp,-1,sizeof(dp));
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin >> arr[i];
   
   int ans=solve(arr,0,0);
   
   cout << ans<< endl;
}