#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int>dist(n+1,0);
    vector<int>parent(n+1,-1);
    vector<bool>vis(n+1,false);
    
    queue<int>q;
    q.push(1);
    vis[1]=true;
    
    bool found=false;
    while(q.size()>0 && !found){
        int node=q.front();
        q.pop();
        
        for(int child:adj[node]){
            if(vis[child]==false){
                parent[child]=node;
                vis[child]=true;
                q.push(child);
                dist[child]=dist[child]+1;
                
                if(child==n){
                    found=true;
                    break;
                }
            }
        }
    }
 
    
    if(!found) cout << "IMPOSSIBLE" << endl;
    else{
        vector<int>ans;
         
        for(int i=n;i!=-1;i=parent[i]){
              ans.push_back(i);
        }
        
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(int ele:ans) cout << ele << " ";
    }
    
    
}