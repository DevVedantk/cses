#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int dp[5001][5001];

int findmax(vector<int>& arr,int start,int end,int turn){
        
    //turn->0  means firstplayer turn
    //turn->1  means sec player turn
    if(start>end) {
     return 0;
    }
    if(dp[start][end]!=-1e8) return dp[start][end];
    
    if(turn==0){
      int pickstart=arr[start]+findmax(arr,start+1,end,1);
      int pickend=arr[end]+findmax(arr,start,end-1,1);
     return dp[start][end]=max(pickstart,pickend);
    } 
  else{
       int pickstart=findmax(arr,start+1,end,0);
       int pickend=findmax(arr,start,end-1,0);
      return dp[start][end]=min(pickstart,pickend);
    }


}

signed main(){
   ios::sync_with_stdio(false); cin.tie(NULL);
  memset(dp,-1e8,sizeof(dp));
    int n;
   cin >> n;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin >> arr[i];

  int ans=findmax(arr,0,n-1,0);

   cout << ans << endl;
}


