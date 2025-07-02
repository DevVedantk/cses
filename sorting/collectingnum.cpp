#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
   
   int n;
   cin >> n;
   vector<int>arr(n);
   unordered_map<int,int>mp;
   for(int i=0;i<n;i++){
      cin >> arr[i];
      mp[arr[i]]=i;
   }
   
   int ans=0;
   int i=1;
   while(i<=n){
      int idx=mp[i];
      while(mp[++i]>idx && i<=n){
          idx=mp[i];
      }
      ans++;
   }
   
   cout << ans << endl;
  
   
   
}