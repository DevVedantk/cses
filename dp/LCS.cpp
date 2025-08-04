#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int dp[1001][1001];
int findans(vector<int>& arr,vector<int>& brr,int i,int j){
    if(i==arr.size() || j==brr.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
   
    int ans=0;
     ans=max(ans,findans(arr,brr,i+1,j));
     ans=max(ans,findans(arr,brr,i,j+1));
    if(arr[i]==brr[j]) ans=max(ans,1+findans(arr,brr,i+1,j+1));

    return dp[i][j]=ans;
}

signed main(){
    int n,m;
    cin >> n >> m;
 memset(dp,-1,sizeof(dp));
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    
    vector<int>brr(m);
    for(int i=0;i<m;i++) cin >> brr[i];
    
    
    int ans=findans(arr,brr,0,0);
    
    cout << ans << endl;
    
    

}