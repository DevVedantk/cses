#include <bits/stdc++.h>
#define endl '\n'


using namespace std;

signed main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      
      int n,x;
      cin >> n >> x;

      vector<int>arr(n);
      for(int i=0;i<n;i++) cin >> arr[i];

      int i=0,j=0;
      int sum=0,cnt=0;

      while(j<n){
        if(sum>x){
            sum-=arr[i];
            i++;
        } else{
            if(sum==x) cnt++;
            sum+=arr[j];
            j++;
        }
      }
    while(i<n){
           sum-=arr[i];
            i++; 
              if(sum==x) cnt++;
    }

      cout << cnt << endl;


}