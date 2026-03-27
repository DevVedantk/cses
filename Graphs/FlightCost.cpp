#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }
    
    vector<vector<int>>dist(n+1,vector<int>(2,LLONG_MAX));
    
    dist[1][0]=0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    
    pq.push({0,1,0});
    
    while(pq.size()>0){
        auto [cost,node,state]=pq.top();
        pq.pop();
        
        if(cost > dist[node][state]) continue;
        
        for(auto [child,wt]:adj[node]){
            if(state==0){
             
             //still no discount
              if(dist[child][0] >( wt+dist[node][state])){
                    dist[child][0]=wt+dist[node][state];
                    pq.push({dist[child][0],child,state});
                }
                
                //take discount
                
                if(dist[child][1] >( wt/2 +dist[node][state])){
                    dist[child][1]=wt/2+dist[node][state];
                    pq.push({dist[child][1],child,1});
                }  
                
            } else{
                //already take so only update 1's
                if(dist[child][1] >( wt+dist[node][state])){
                    dist[child][1]=wt+dist[node][state];
                    pq.push({dist[child][1],child,state});
                }
            }
        }
    }
    
    cout << dist[n][1] << endl;
    
}