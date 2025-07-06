#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;
const int INF=1e18;
const int MOD=1e9+7;

int findpow(int a,int b){
    if(b==0) return 1;
    int half=findpow(a,b/2);
    if(b%2==0) return half*half;
    else return a*half*half; 
}

int findceil(int a,int b){
    return (a+b-1)/b;
}


signed main(){
    int n;
    cin >> n;
    
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        mp[ele]++;
    }

    int ans=1;
    for(auto ele:mp){
      ans=(ans%MOD*(ele.second+1))%MOD;
    }

  cout << (ans%MOD-1)%MOD << endl;



    
}