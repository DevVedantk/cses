#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m ;
    
    vector<vector<pair<int,int>>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        adj[a].push_back({b,wt});
    }
    
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

pq.push({0,1});  
vector<int>dist(n+1,LLONG_MAX);

dist[1]=0;
while(pq.size()>0){
    auto [dis,node]=pq.top();
    pq.pop();
    
    if(dis>dist[node]) continue;
    
    for(auto [child,wt]:adj[node]){
        if(dist[child]>wt+dis){
            dist[child]=wt+dis;
            pq.push({dist[child],child});
        }
    }
}

for(int i=1;i<=n;i++) cout << dist[i] << " ";
    
    
    
    
}