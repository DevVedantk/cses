#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s1,s2;
    cin >> s1 >> s2;
    
    int n=s1.size(),m=s2.size();
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=0;i<=m;i++) dp[0][i]=i;

    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(s1[i]==s2[j]){
                dp[i+1][j+1]=dp[i][j];
            } else dp[i+1][j+1]=min(dp[i][j+1],min(dp[i+1][j],dp[i][j]))+1;
        }
    }

    cout << dp[n][m] << endl;
    
}