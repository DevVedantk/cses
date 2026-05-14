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
        int a,b,wt;
        cin >> a >> b >> wt;
        edges[i]={a,{b,wt}};
        adj[a].push_back(b);
    }
    
    vector<int>dist(n+1,LLONG_MIN);
    
    dist[1]=0;
    for(int i=0;i<n-1;i++){
         for(auto& [u,p]:edges){
              int v=p.first,wt=p.second;
              if(dist[u]!=LLONG_MIN && dist[v]<(dist[u]+wt)){
                  dist[v]=dist[u]+wt;
              }
         }
    }
    
    set<int>cycle_node;
    for(auto& [u,p]:edges){
        int v=p.first,wt=p.second;
        if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+wt){
                 cycle_node.insert(v);
              }
    }
    
    vector<bool>vis(n+1,false);
    queue<int>cy_node;
    queue<int>q;
    vis[1]=true;
    q.push(1);
    
    
    while(q.size()>0){
        int node=q.front();
        q.pop();
        
        if(cycle_node.find(node)!=cycle_node.end()){
            cy_node.push(node);
        }
        for(int child:adj[node]){
            if(vis[child]==false){
                vis[child]=true;
                q.push(child);
            }
        }
    }
    
    bool find=false;
    vis.assign(n+1,false);
    
    while(cy_node.size()>0){
        int node=cy_node.front();
        cy_node.pop();
        
        if(node==n){
            find=true;
            break;
        }
        for(int child:adj[node]){
            if(vis[child]==false){
                vis[child]=true;
                cy_node.push(child);
            } 
        }
    }
    
    if(find) cout << -1 << endl;
    else cout << dist[n] << endl;
    
    
    
    
    
}

