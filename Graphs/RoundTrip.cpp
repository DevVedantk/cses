#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<bool>vis;
vector<int>par;

int cy_st=-1,cy_en=-1;
bool dfs(int node,int parent,vector<vector<int>>&adj){
    vis[node]=true;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        
        if(vis[child]){
           cy_st=child;
           cy_en=node;
           return true;
        }
       else if(vis[child]==false){
           par[child]=node;
            if(dfs(child,node,adj)) return true;
        }
    }
    
    return false;
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>>adj(n+1);
    par.assign(n+1,-1);
    vis.assign(n+1,false);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(vis[i]==false && dfs(i,-1,adj)) break;
    }
    
    if(cy_st==-1) cout << "IMPOSSIBLE" << endl;
    else{
        vector<int>cycle;
        cycle.push_back(cy_st);
        int curr=cy_en;
        while(curr!=cy_st){
            cycle.push_back(curr);
            curr=par[curr];
        }
         cycle.push_back(cy_st); // close cycle
         cout << cycle.size() << endl;
         for(int ele:cycle) cout << ele << " ";
         
    }
    
}