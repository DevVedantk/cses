#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

bool mysort(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0]<b[0];
    return a[1] > b[1];                 
}

signed main(){ 
    ios::sync_with_stdio(false); cin.tie(NULL);
     int n;
     cin >> n;
     
     vector<vector<int>>arr(n,vector<int>(3));
      
     for(int i=0;i<n;i++){
       cin >> arr[i][0]; 
       cin >> arr[i][1]; 
       arr[i][2]=i;
     }
     
     //
     sort(arr.begin(),arr.end(),mysort);
      
      vector<bool>contains(n,false);
      vector<bool>contained(n,false);
      
      
      int i=0;
      int maxright=INT_MIN;
      
      while(i<n){
          if(arr[i][1]>maxright){
              maxright=arr[i][1];
          } else{
             contained[arr[i][2]]=true; 
          }
          i++;
      }
      
      i=n-1;
      int minright=INT_MAX;
      while(i>=0){
          if(arr[i][1]<minright) minright=arr[i][1];
          else contains[arr[i][2]]=true;
          i--;
      }
      
      for(int i=0;i<n;i++){
          if(contains[i]==true) cout << 1 << " ";
          else cout << 0 << " ";
      }
      cout << endl;
      
       for(int i=0;i<n;i++){
          if(contained[i]==true) cout << 1 << " ";
          else cout << 0 << " ";
      }
     
     
     
}