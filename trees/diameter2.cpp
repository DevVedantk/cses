#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>depth;
void dfs(int parent,int node,vector<vector<int>>& adj){
    for(int child:adj[node]){
        if(parent==child) continue;
        depth[child]=depth[node]+1;
        dfs(node,child,adj);
    }    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
     
     int n;
     cin >> n;
     depth.assign(n+1,0);
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(-1,1,adj);
    int dia=0;
    
    int maxd=-1,maxnode=0;
    for(int i=1;i<=n;i++){
        if(depth[i]>=maxd){
            maxd=depth[i];
            maxnode=i;
        }
        depth[i]=0;
    }
    
    dfs(-1,maxnode,adj);
    for(int i=1;i<=n;i++){
        dia=max(dia,depth[i]);
    }
    
    cout << dia << endl;
    
    
    
}