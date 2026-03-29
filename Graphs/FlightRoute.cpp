#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m,k;
    cin >> n >> m >> k;
    
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }
    
    vector<vector<int>>dist(n+1);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     
     pq.push({0,1});
     dist[1].push_back(0);
     
     while(pq.size()>0){
         auto [dis,node]=pq.top();
         pq.pop();
         
         if(dist[node].size()==k && (dis > dist[node].back())) continue;
         
         for(auto [child,wt]:adj[node]){
    
             if(dist[child].size()<k){
                 dist[child].push_back(dis+wt);
                 sort(dist[child].begin(),dist[child].end());
                 pq.push({dis+wt,child});
             } else if(dist[child].size()==k && (dist[child].back()>(dis+wt))) {
                 dist[child].back()=(dis+wt);
                   sort(dist[child].begin(),dist[child].end());
                 pq.push({dis+wt,child});
             }
         }
     }
     
     for(int ele:dist[n]) cout << ele << " ";
          
    
}

