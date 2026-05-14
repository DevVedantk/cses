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
        int a,b,wt;
        cin >> a >>b >> wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    
    vector<bool>vis(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    
    int tot=0;
    while(pq.size()>0){
        auto [cost,node]=pq.top();
        pq.pop();
        if(vis[node]) continue;
        
        vis[node]=true;
        tot+=cost;
        
        for(auto [child,wt]:adj[node]){
            if(!vis[child]){
                pq.push({wt,child});
            }
        }
    }
    
    bool f=true;
    for(int i=1;i<=n;i++) {
        if(vis[i]==false){
             f=false;
            break;
        }
    }
    
    if(!f) cout << "IMPOSSIBLE" << endl;
    else cout << tot << endl;
    
}