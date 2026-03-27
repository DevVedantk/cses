#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>>adj(n+1);
    vector<pair<int,pair<int,int>>>edges(m);
    
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges[i]={u,{v,wt}};
        adj[u].push_back(v);
    }
    
    vector<int>dist(n+1,LLONG_MAX);
    
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto [u,p]:edges){
            int v=p.first,wt=p.second;
            if(dist[u]!=LLONG_MAX && (dist[u]+wt)<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    //detect positive cycle
     set<int>cycle_node;
       for(auto [u,p]:edges){
            int v=p.first,wt=p.second;
            if(dist[u]!=LLONG_MAX && (dist[u]+wt)<dist[v]){
                 cycle_node.insert(v);
            }
        }
       
        
        if(cycle_node.size()==0) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(auto x:cycle_node){
                cout << x << " ";
            }
        }
    
}