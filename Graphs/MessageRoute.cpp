#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


vector<int>vis;

vector<int>parent;
vector<int>dist;


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    vis.assign(n+1,false);
    parent.assign(n+1,-1);
    dist.assign(n+1,0);
    
    vector<int>path;
    
    vector<vector<int>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int>q;
    q.push(1);
    vis[1]=true;
    
   
    bool found=false;
    while(q.size()>0 && !found){
        int node=q.front();
        q.pop();
    
        for(int child:adj[node]){
            if(vis[child]==false){
                vis[child]=true;
                q.push(child);
                dist[child]=dist[node]+1;
                parent[child]=node;
                if(child==n){
                    found=true;
                     break;
                }
            } 
        }
    }
    
    
    if(vis[n]==false) cout << "IMPOSSIBLE" << endl;
    else{
    cout << dist[n]+1 << endl;
         
         for(int i=n;i!=-1;i=parent[i]){
             path.push_back(i);
         }
         reverse(path.begin(),path.end());
         
         for(int ele:path) cout << ele << " ";
         
    }
    
    
    
}