#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
#define int long long
signed main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
     
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i>0) arr[i]+=arr[i-1];
    }


    map<int,int>mp;
    mp[0]=1;
    int cnt=0;
    for(int i=0;i<n;i++){ 
      int mod;
      if(arr[i]>=0) mod=arr[i]%n;
      else mod=((arr[i] % n) + n) % n;
      
     if(mp.find(mod)!=mp.end()) cnt+=mp[mod];
     mp[mod]++;
    }

    cout << cnt << endl;

}