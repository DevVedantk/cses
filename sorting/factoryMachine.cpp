#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

bool check(int time,vector<int>& arr,int t){
    int total=0;
      for(int i=0;i<arr.size();i++){
        total+=(time/arr[i]);
        if(total>=t) return true;
      }
      return false; 
}

signed main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      
      int n,t;
      cin >> n >> t;

      vector<int>arr(n);
      for(int i=0;i<n;i++) cin >> arr[i];

      sort(arr.begin(),arr.end());
    
      int left=1,right=arr[0]*t;

       int ans=1e18;
      while(left<=right){
        int mid= left+(right-left)/2;
        
        if(check(mid,arr,t)){
            ans=min(ans,mid);
           right=mid-1; 
        } else left=mid+1;
      }
  
      cout << ans << endl;

}