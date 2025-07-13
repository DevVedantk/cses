#include <bits/stdc++.h>
#define endl '\n'

#define int long long
using namespace std;


signed main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
    
  int n,x;
  cin >> n >> x;
  vector<int>prefix(n);
  
  for(int i=0;i<n;i++){
    cin >> prefix[i];
    if(i>0) prefix[i]+=prefix[i-1];
  }

  map<int,int>mp;
  
  mp[0]=1;
  int cnt=0;
  for(int i=0;i<n;i++){ 
      if(mp.find(prefix[i]-x)!=mp.end()){
        cnt+=mp[prefix[i]-x];
      }
      mp[prefix[i]]++;
  }


  cout << cnt << endl;
  


  
}