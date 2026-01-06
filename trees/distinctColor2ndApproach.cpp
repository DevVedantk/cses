#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>col;
vector<int>ans;
vector<set<int>*> st;

void dfs(int node,int parent,vector<vector<int>>& adj){
    
    int mx=0,maxnode=-1;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        dfs(child,node,adj);
        if(st[child]->size() > mx){
            mx=st[child]->size();
            maxnode=child;
        }
    }
    
    if(maxnode==-1) st[node]=new set<int>();
    else st[node]=st[maxnode];
    
    
    st[node]->insert(col[node]);
    
    for(int child:adj[node]){
        if(child==parent || child==maxnode) continue;
        for(int color:*st[child]){
            st[node]->insert(color);
        }   
    }
    ans[node]=st[node]->size();
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    col.assign(n+1,0);
    ans.assign(n+1,0);
    st.assign(n+1,0);
    // vector<int>col(n+1);
    for(int i=1;i<=n;i++) cin >> col[i];
    
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,-1,adj);
    
  
  for(int i=1;i<=n;i++) cout << ans[i] << " ";
    
}