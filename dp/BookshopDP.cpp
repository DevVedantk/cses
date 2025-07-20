#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,x;
    cin >> n >> x;
    vector<int>pri(n);
    vector<int>page(n);

    for(int i=0;i<n;i++) cin >> pri[i];
    for(int i=0;i<n;i++) cin >> page[i];
    
    vector<int>memo(x+1,0);

    memo[0]=0;
    
   for (int i = 0; i < n; i++) {
        for (int j = x; j >= pri[i]; j--) {
            memo[j] = max(memo[j], memo[j - pri[i]] + page[i]);
        }
    }
        
    cout << memo[x] << endl;


}