#include <bits/stdc++.h>
#define int long long  
#define endl '\n'

using namespace std;

    int n,m;
    vector<int>ans;


bool bfs(int node,vector<vector<int>>&adj){
      queue<int>q;
      q.push(node);
      ans[node]=1;
      
       while(q.size()>0){
           int node=q.front();
           q.pop();
           
           for(int child:adj[node]){
               if(ans[child]==-1){
                  ans[child]=3-ans[node];
                  q.push(child);
               } else if(ans[child]==ans[node]) return false;
           }
       }
       
       return true;
    }
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    ans.assign(n+1,-1);
    vector<vector<int>>adj(n+1);
   
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bool f=true;
    for(int i=1;i<=n;i++){
        if(ans[i]==-1){
          if(!bfs(i,adj)){
           f=false;
           break;
          }
        }
    }
    
    if(!f) cout << "IMPOSSIBLE" << endl;
    else{
         for(int i=1;i<=n;i++) cout << ans[i] << " "; 
    }
    
    
}