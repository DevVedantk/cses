#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int up[200001][20];
int lvl[200001];

vector<int>ans;

void find_level(int node,int parent,vector<vector<int>>& adj,int level){
      lvl[node]=level;
      
      for(int child:adj[node]){
          if(child==parent) continue;
          find_level(child,node,adj,level+1);
      }
}
void binary_lif(int node,int parent,vector<vector<int>>& adj){
    up[node][0]=parent;
    
    for(int i=1;i<20;i++){
        if(up[node][i-1]!=-1){
            up[node][i]=up[up[node][i-1]][i-1];
        } else up[node][i]=-1;
    }
    
    for(int child:adj[node]){
        if(child==parent) continue;
        binary_lif(child,node,adj);
    }
}
int get_node(int node,int jump){
    if(node==-1 || jump==0) return node;
    
    for(int i=19;i>=0;i--){
        if(jump>=(1<<i)){
            return get_node(up[node][i],jump-(1<<i));
        }
    }
    return -1;
}

int lca(int u,int v){
    if(lvl[u]<lvl[v]) swap(u,v);
    
    u=get_node(u,lvl[u]-lvl[v]);
    
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    
    return get_node(u,1);
}


void dfs(int node,int parent,vector<vector<int>>& adj){
    
    
    for(int child:adj[node]){
        if(child==parent) continue;
        dfs(child,node,adj);
        ans[node]+=ans[child];
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    ans.assign(n+1,0);
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
   find_level(1,-1,adj,0);
   binary_lif(1,-1,adj);
   
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        
        int lca_node=lca(u,v);
        int parent_lca=get_node(lca_node,1);
        ans[u]++;
        ans[v]++;
        ans[lca_node]--;
        if(parent_lca!=-1) ans[parent_lca]--;
    }
    dfs(1,-1,adj);
    
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    
    
}