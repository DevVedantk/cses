#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);  
    
    int n,m;
    cin >> n >> m;

    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    
    vector<int>brr(m);
    for(int j=0;j<m;j++) cin >> brr[j];
    
   int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++) dp[i][j]=0;
    
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(arr[i]==brr[j]){
            dp[i+1][j+1]=dp[i][j]+1;
           } else{
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
           }
        }
    }
     
     cout << dp[n][m] << endl;
     
     int i=n,j=m;
     while (i > 0 && j > 0) {
    if (arr[i - 1] == brr[j - 1]) {
        ans.push_back(arr[i - 1]);
        i--;
        j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
    } else {
        j--;
    }
}

     reverse(ans.begin(),ans.end());

     for(int ele:ans) cout << ele << " ";
     

    }




