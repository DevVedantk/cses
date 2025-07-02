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
    
    int currsum=0;
    for(int i=0;i<n;i++){
        if(i+1<n && arr[i]>(currsum+1)){
            currsum++;
            break;
        } if(i==n-1) currsum++;
        currsum+=arr[i];
    }

    cout << currsum << endl;

}