#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;
signed main(){
    int n,wt;
    cin >> n >> wt;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<pair<int,int>>dp(1<<n,{1e9,1e9});

    dp[0]={1,0};

    for(int mask=0;mask<(1<<n);mask++){
        for(int bit=0;bit<n;bit++){
            if((mask&(1<<bit))){
             int space_taken=dp[mask^(1<<bit)].second;
             
             if(space_taken+arr[bit]<=wt){
                dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].first,space_taken+arr[bit]});
             } else{
                dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].first+1,arr[bit]});
             }
            }
        }
    }

    cout << dp[(1<<n)-1].first << endl;
     
}