#include <bits/stdc++.h>
#define int long long
#define endl '\n'

#define MP make_pair

using namespace std;
int inf=1e9;
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    pair<int,pair<int,int>>arr[n];
    
    for(int i=0;i<n;i++){
        int l,r,p;
        cin >> l >> r >> p;
        arr[i]=MP(l,MP(r,p));
    }
    
    //binary search and knapsack
    sort(arr,arr+n);
    long long dp[n+1];
    for(int i=n;i>=0;i--){
        if(i==n) dp[i]=0;
         else{
           //dont take or either take
           dp[i]=dp[i+1];
           int nextval=arr[i].second.first;
auto it=upper_bound(arr,arr+n,MP(nextval,MP(inf,inf)))-arr;
           dp[i]=max(dp[i],arr[i].second.second+dp[it]);
         }
    }
    
    cout << dp[0] << endl;
}