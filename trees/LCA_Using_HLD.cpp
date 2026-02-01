#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>sizes,heavy,parent,depth,head,lt,pos;
int idx=0;

void dfs(int node,int par,vector<vector<int>>&adj){
           parent[node]=par;
       
       for(int child:adj[node]){
           if(child==par) continue;
           depth[child]=depth[node]+1;
           dfs(child,node,adj);
           
           sizes[node]+=sizes[child];
           if(sizes[child]>sizes[heavy[node]]){
               heavy[node]=child;
           }
       }
       sizes[node]++;
}

void dfsHLD(int node,int par,int chain,vector<vector<int>>&adj){
     head[node]=chain;
     pos[node]=idx;
     idx++;
 
     if(heavy[node]!=0){
         dfsHLD(heavy[node],node,chain,adj);
     }
     for(int child:adj[node]){
         if(child==par) continue;
         
          if(heavy[node]!=child){
              dfsHLD(child,node,child,adj);
          }
     }
}

int LCA(int a,int b){
    
    while(head[a]!=head[b]){
        if(depth[head[a]] < depth[head[b]]){
               swap(a,b);       
        }
        a=parent[head[a]];
    }
    
    if(depth[a]<depth[b]) swap(a,b);
    return b;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    vector<vector<int>>adj(n+1);
    
    for(int i=2;i<=n;i++){
        int a;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    
    sizes.assign(n+1,0);
    heavy.assign(n+1,0);
    parent.assign(n+1,0);
    depth.assign(n+1,0);
       
    dfs(1,0,adj);
    
    head.assign(n+1,0);
    lt.assign(n+1,0);
    pos.assign(n+1,0);
    
    dfsHLD(1,0,1,adj);  
    
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        
        int ans=LCA(a,b);
        cout << ans << endl;
    }
    
}