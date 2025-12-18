#include <bits/stdc++.h>
#define int long long
#define endl '\n'


int dp[200001][2];
using namespace std;

void solve(int node,int parent,vector<vector<int>>& adj){
    
    for(int child:adj[node]){
        if(child==parent) continue;
        solve(child,node,adj);
        dp[node][0]+=max(dp[child][0],dp[child][1]);
    } 
    
    for(int child:adj[node]){
        if(child==parent) continue;
        dp[node][1]=max(dp[node][1],dp[node][0]-max(dp[child][0],dp[child][1])+dp[child][0]+1);
    }
     
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    solve(1,-1,adj);
    cout << max(dp[1][0],dp[1][1]) << endl;
}