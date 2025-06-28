#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    vector<int>arr(n);
    vector<int>brr(m);

    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<m;i++) cin >> brr[i];
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());

    int i=0,j=0;
    int cnt=0;
    while(i<n && j<m){
      if((arr[i]-k)>brr[j]) j++;
      else if((arr[i]+k)<brr[j]) i++;
      else{
         cnt++;
         i++;
         j++;
      }
    }

    cout << cnt << endl;

}