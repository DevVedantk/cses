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
    int n,x;
    cin >> n >> x;
    vector<int>arr(n);
    
    multimap<int,int>mp;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp.insert({arr[i],i}); 
    }
     
    
    int left=0,right=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(mp.find(x-arr[i])!=mp.end()){
         auto it=mp.find(x-arr[i]);
          if(it->second!=i){
            left=it->second+1;
            right=i+1;
            flag=true;
            break;
          }
        }
    }

    if(flag) cout << left << " " << right << endl;
    else cout << "IMPOSSIBLE" << endl;
    

}