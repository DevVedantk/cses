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

    int cnt=1;
    for(int i=0;i<n-1;i++){
       if(arr[i]!=arr[i+1]) cnt++; 
    }
    // if(n>2 && arr[n-1]!=arr[n-2]) cnt++;
    
    cout << cnt << endl;
    
}