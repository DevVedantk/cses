#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum=0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum+=arr[i];
    }
    
    vector<int>dp(sum+1,0);
     dp[0]=1;
    

   for(int i=0;i<n;i++){
    for(int j=sum;j>=0;j--){
       if(j>=arr[i]) dp[j] |= dp[j-arr[i]];
    }
   }

   int cnt=0;
   for(int i=1;i<=sum;i++){
    if(dp[i]==1) cnt++;
   }

   cout << cnt << endl;
     for(int i=1;i<=sum;i++){
         if(dp[i]) cout << i << " ";
     }


   
}
