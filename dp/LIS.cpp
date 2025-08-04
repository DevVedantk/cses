#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

   
    vector<int>dp(n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(dp[i]==0) dp[i]=1;
    }

sort(dp.begin(),dp.end());


}