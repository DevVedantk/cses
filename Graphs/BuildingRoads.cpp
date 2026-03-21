#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
vector<int>city;
vector<bool>vis;
void dfs(int node,vector<vector<int>>&adj){
     
     vis[node]=true;
     for(int child:adj[node]){
         if(vis[child]==false){
             dfs(child,adj);
         }
     }
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vis.assign(n+1,false);
    
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int road=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            city.push_back(i);
            dfs(i,adj);
            road++;
        }
    }
    road--;
    if(road==0){
        cout << 0 << endl;
    } else{
    cout << road << endl;
    for(int i=0;i<city.size();i++){
        if(i+1<city.size()){
            cout << city[i] << " " << city[i+1] << endl;
        }
    }
    }
    
    
    
}