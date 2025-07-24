#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int dp[1000001][2];
int MOD=1e9+7;

void fn(){
    
    dp[1][1]=1;
    dp[1][0]=1;
    for(int i=2;i<=1000000;i++){
        dp[i][0]=((dp[i-1][0]*4)%MOD + (dp[i-1][1])%MOD)%MOD;
        dp[i][1]=((dp[i-1][1]*2)%MOD + (dp[i-1][0])%MOD)%MOD;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    fn();
    int t;
    cin >> t;
    while(t-- >0){
        int n;
        cin >> n;

cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
}