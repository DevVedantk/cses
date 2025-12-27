#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    int len=ceil(sqrt(n));
    vector<int>sqrtarr(len,1e9);
    
    int mine=1e9;
    for(int i=0;i<n;i++){
       int idx=i/len;
       sqrtarr[idx]=min(sqrtarr[idx],arr[i]);
    }
    
  
      for(int i=0;i<q;i++){
          int l,r;
          cin >> l >> r;
          l--;r--;
           mine=1e9;
          while(l<=r){
              if(l%len==0 && l+len-1<=r){
                  mine=min(mine,sqrtarr[l/len]);
                  l+=len;
              } else{
                  mine=min(mine,arr[l]);
                  l++; 
              }
          }
          cout << mine << endl;
          
      }
}

