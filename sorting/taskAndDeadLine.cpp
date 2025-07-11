#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      
      int n;
      cin >> n;

       vector<pair<int,int>>arr(n);
       for(int i=0;i<n;i++){
         cin >> arr[i].first; 
         cin >> arr[i].second; 
       }

       sort(arr.begin(),arr.end());

       int currentTime=0;
       int ans=0;
       for(int i=0;i<n;i++){
        currentTime+=arr[i].first;
        ans+=(arr[i].second-currentTime);
       }

       cout << ans << endl;


}