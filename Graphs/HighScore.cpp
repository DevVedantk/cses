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
    
    vector<int>dist(n+1,LLONG_MIN);
    
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto [u,p]:edges){
            int v=p.first,wt=p.second;
            if(dist[u]!=LLONG_MIN && (dist[u]+wt)>dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    //detect positive cycle
     set<int>cycle_node;
       for(auto [u,p]:edges){
            int v=p.first,wt=p.second;
            if(dist[u]!=LLONG_MIN && (dist[u]+wt)>dist[v]){
                 cycle_node.insert(v);
            }
        }
        
        vector<bool>vis(n+1,false);
        
        //check from 1 to cycle path or not
        queue<int>cycle_q;
        queue<int>q;
        q.push(1);
         vis[1]=true;
        while(q.size()>0){
            int node=q.front();
            q.pop();
            
            
            if(cycle_node.find(node)!=cycle_node.end()){
                cycle_q.push(node);
            }
            
            for(int child:adj[node]){
                if(vis[child]==false){
                     q.push(child);
                vis[child]=true;
                }
            }
        }
        
      vis.assign(n+1,false);
        bool flag=false;
        while(cycle_q.size()>0){
            int node=cycle_q.front();
            cycle_q.pop();
            
           
            
            if(node==n){
                flag=true;
                break;
            }
            
            for(int child:adj[node]){
                if(vis[child]==false){
                     cycle_q.push(child);
                vis[child]=true;
                }
            }
        }
        
        if(flag) cout << -1 << endl;
        else cout << dist[n] << endl;
    
}