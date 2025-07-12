#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    int remainingSum=accumulate(arr.begin(),arr.end()-1,0ll);

    if(remainingSum>=arr[n-1]) cout << arr[n-1]+remainingSum << endl;
    else cout << 2*arr[n-1] << endl;
    
}