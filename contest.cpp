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
        int x;
        cin >> x;

        bool flag=false;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                flag=true;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

      
    
}