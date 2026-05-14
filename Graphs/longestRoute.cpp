#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
 
 vector<vector<int>>adj(n+1);
 vector<int>deg(n+1,0);
 vector<int>dp(n+1,-1e18);
 
 for(int i=0;i<m;i++){
     int u,v;
     cin >> u >> v;
     adj[u].push_back(v);
     deg[v]++;
 }
 
 queue<int>q;
 for(int i=1;i<=n;i++){
     if(deg[i]==0) q.push(i);
 }
    
    vector<int>res;
    while(q.size()>0){
        int node=q.front();
        q.pop();
        
        res.push_back(node);
        for(int child:adj[node]){
            deg[child]--;
            if(deg[child]==0) q.push(child);
        }
    }
    
    vector<int>par(n+1,-1);
    dp[1]=0;
    
    for(int u:res){
       if(dp[u]==-1e18) continue;
        for(int v:adj[u]){
           if(dp[v]<(dp[u]+1)){
               dp[v]=dp[u]+1;
               par[v]=u;
           }
        }
    }
    int end=n;
    
    vector<int>path;
    while(end!=-1){
        path.push_back(end);
        end=par[end];
    }
    if(dp[n]==-1e18){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } else{

        cout << path.size() << endl;
        
        reverse(path.begin(),path.end());
        for(int ele:path) cout << ele << " ";
    }
 
}