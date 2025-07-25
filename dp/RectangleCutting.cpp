
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a,b;
    cin >> a >> b;
    
     vector<vector<int>>dp(a+1,vector<int>(b+1,INT_MAX));

     for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j) dp[i][j]=0;
        }
     }
     

     for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            
            //horizontal cuts
           for(int k=1;k<i;k++){
             dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
           } 

           
            //vertical cuts
           for(int k=1;k<j;k++){
             dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
           } 
        }
     }

    
        cout << dp[a][b] << endl;
    }
    
    
