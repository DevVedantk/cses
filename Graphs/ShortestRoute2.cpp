#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m,q;
    cin >> n >> m >> q;
    
    vector<vector<pair<int,int>>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,LLONG_MAX));
    
    for(int i=1;i<=n;i++){
            dp[i][i]=0;
    }
    
    for(int i=0;i<adj.size();i++){
        int u=i;
        for(auto [v,wt]:adj[i]){
           dp[u][v]=min(dp[u][v],wt);
           dp[v][u]=min(dp[v][u],wt);
        }
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k]!=LLONG_MAX && dp[k][j]!=LLONG_MAX){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
    }
    
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        if(dp[a][b]==LLONG_MAX) cout << -1 << endl;
        else cout << dp[a][b] << endl;
    }
    
    
}