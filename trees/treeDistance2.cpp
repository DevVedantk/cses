#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>subtreeNode;
vector<int>ans;
vector<int>depth;

void dfs(int node,int parent,vector<vector<int>>& adj){
    
    for(int child:adj[node]){
       if(child==parent) continue;
       depth[child]=1+depth[node];
       dfs(child,node,adj);
    }
}

int FindSubTreeNodes(int node,int parent,vector<vector<int>>& adj){
    int cnt=1;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        cnt+=FindSubTreeNodes(child,node,adj);
    }
    subtreeNode[node]=cnt;
    return cnt;
}

void solve(int node,int parent,vector<vector<int>>& adj,int n){
     
     for(int child:adj[node]){
         if(child==parent) continue;
         
             int x=subtreeNode[child];
             ans[child]=ans[node]-x+(n-x);
             solve(child,node,adj,n);
         
     }
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    
    subtreeNode.assign(n+1,0);
    ans.assign(n+1,0);
    depth.assign(n+1,0);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    FindSubTreeNodes(1,-1,adj);
    
    dfs(1,-1,adj);
    
    int sum=0;
    for(int i=1;i<=n;i++) sum+=depth[i];
    
    ans[1]=sum;
    
    solve(1,-1,adj,n);
    
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    
    
}