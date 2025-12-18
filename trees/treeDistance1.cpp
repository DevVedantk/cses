#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>depth;
vector<int>ans;

void find_depth(int node,int parent,vector<vector<int>>& adj){
    int dep=0;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        find_depth(child,node,adj);
        dep=max(dep,1+depth[child]);
    }
    depth[node]=dep;
}

void dfs(int node,int parent,int p_ans,vector<vector<int>>& adj){
     vector<int>prefix_max,suff_max;
     
     for(int child:adj[node]){
         if(child==parent) continue;
         prefix_max.push_back(depth[child]);
         suff_max.push_back(depth[child]);
     }
     
     for(int i=1;i<prefix_max.size();i++)
     prefix_max[i]=max(prefix_max[i],prefix_max[i-1]);
     
       for(int i=suff_max.size()-2;i>=0;i--)
     suff_max[i]=max(suff_max[i],suff_max[i+1]);
       
       int c_no=0;
       for(int child:adj[node]){
           if(child==parent) continue;
           
     int op1=(c_no==0) ? -1e9 : prefix_max[c_no-1];
     int op2=(c_no==suff_max.size()-1) ? -1e9 : suff_max[c_no+1];
     int partial_ans=1+max(p_ans,max(op1,op2));
     dfs(child,node,partial_ans,adj);
     c_no++;
       }
       ans[node]=1+max(p_ans,(prefix_max.empty()?-1:prefix_max.back()));
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    depth.assign(n+1,0);
    ans.assign(n+1,0);
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    find_depth(1,-1,adj);
    dfs(1,-1,-1,adj);
    
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    
    
}