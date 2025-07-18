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
    int t;
    cin >> t;
    while(t-- >0){
        int n,k;
        cin >> n >> k;
    
        int cnt=0;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];

        int j=0;

        while(j<n){
            int ele=0;
          while(arr[j]==0 && ele<k){
            j++;
            ele++;
          }
          if(ele==k) cnt++;
          j++;
        }
       cout << cnt << endl;

    }  
}