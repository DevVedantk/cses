#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

vector<int>lvl;
int up[200001][20];

void dfs(int node,int parent,vector<vector<int>>& adj,int level){
     lvl[node]=level;
     
     for(int child:adj[node]){
         if(child==parent) continue;
         dfs(child,node,adj,level+1);
     }
}

void binary_lifting(int node,int parent,vector<vector<int>>& adj){
    up[node][0]=parent;
    
    for(int i=1;i<20;i++){
        if(up[node][i-1]!=-1){
            up[node][i]=up[up[node][i-1]][i-1];
        } else up[node][i]=-1;
    }
    
    for(int child:adj[node]){
        if(child==parent) continue;
        binary_lifting(child,node,adj);
    }
}

int get_node(int node,int jump_req){
     if(node==-1 || jump_req==0) return node;
     
     for(int i=19;i>=0;i--){
         if(jump_req>=(1<<i)){
             return get_node(up[node][i],jump_req-(1<<i));
         }
     }
     return -1;
}

int lca(int u,int v){
    //lca of u and v
    if(lvl[u]<lvl[v]){
        swap(u,v);
    }
    
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


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
   vector<vector<int>>adj(n+1);
   lvl.assign(n+1,0);
   
   for(int i=2;i<=n;i++){
        int a;
        cin >> a ;
        adj[a].push_back(i);
        adj[i].push_back(a);
   }
   dfs(1,-1,adj,0);
   binary_lifting(1,-1,adj);
   
   for(int i=0;i<q;i++){
       int a,b;
       cin >> a >> b;
      int ans=lca(a,b);
      cout << ans << endl;
   }
   
   
   
}