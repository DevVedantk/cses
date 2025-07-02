#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;
const int INF=1e18;
const int MOD=1e9+7;

int findpow(int a,int b){ if(b==0) return 1; int half=findpow(a,b/2); if(b%2==0) return half*half; else return a*half*half;}
int findceil(int a,int b){return (a+b-1)/b;}

signed main(){
    int   n;
    cin >> n;

    vector<int>arr(n);
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
         cin >> arr[i];
         mp[arr[i]]=i;
    }

    sort(arr.begin(),arr.end());
     
    int ans=1;
     for(int i=1;i<n;i++){
       int idx1=mp[arr[i]]; 
       int idx2=mp[arr[i]-1];
       if(idx2>idx1) ans++; 
     }
  cout << ans << endl;

}