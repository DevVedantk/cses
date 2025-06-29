#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){

     int n;
     cin >> n;
     vector<int>arr(n);

     for(int i=0;i<n;i++) cin >> arr[i];

     sort(arr.begin(),arr.end());
     int median=arr[n/2];
      int cost=0;
     for(int i=0;i<n;i++) cost+=(abs(arr[i]-median));
cout << cost << endl;
     
   }
