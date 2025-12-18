#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>depth;
vector<int>d1;
vector<int>d2;

void dfs(int node,int parent,vector<vector<int>>& adj){
      for(int child:adj[node]){
          if(parent==child) continue;
          depth[child]=1+depth[node];
          dfs(child,node,adj);
      }    
}

signed main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<vector<int>>adj(n+1);
  depth.assign(n+1,0);
  for(int i=1;i<=n-1;i++){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  dfs(1,-1,adj);
  
  int maxd=-1,node1=0;
  for(int i=1;i<=n;i++){
      if(depth[i]>=maxd){
          maxd=depth[i];
          node1=i;
      }
      depth[i]=0;
  }
  
  dfs(node1,-1,adj);
  
  int node2=0;
  maxd=0;
  for(int i=1;i<=n;i++){
      if(depth[i]>=maxd && i!=node1){
          maxd=depth[i];
          node2=i;
      }
      depth[i]=0;
  }
  
  d1.assign(n+1,0);
  dfs(node1,-1,adj);
  
  for(int i=1;i<=n;i++){
      d1[i]=depth[i];
      depth[i]=0;
  }
  
  d2.assign(n+1,0);
  
   dfs(node2,-1,adj);
  
  for(int i=1;i<=n;i++){
      d2[i]=depth[i];
  }
  for(int i=1;i<=n;i++){
      cout << max(d1[i],d2[i]) << " ";
  }
  
  
  
    
}