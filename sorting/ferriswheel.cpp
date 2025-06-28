#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
signed main(){
    int n,x;
    cin >> n >> x;

    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    int i=0,j=n-1;
    int cnt=0;
    while(i<=j){
        if(arr[j]+arr[i]>x){
            cnt++;
            j--;
        } else {
            i++;
            j--;
            cnt++;
        }
    }

    cout << cnt << endl;
}