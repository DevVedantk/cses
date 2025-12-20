#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int up[200001][20];

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

int ans_query(int node,int jump_req){
    if(node==-1 || jump_req==0) return node;
    
    for(int i=19;i>=0;i--){
        if(jump_req>=(1<<i)){
            return ans_query(up[node][i],jump_req-(1<<i));
        }
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
    vector<vector<int>>adj(n+1);
    
    for(int i=2;i<=n;i++){
        int node;
        cin >> node;
        adj[i].push_back(node);        
        adj[node].push_back(i);        
    }
    
    binary_lifting(1,-1,adj);
    
    for(int i=0;i<q;i++){
        int node,k;
        cin >> node >> k;
        int ans=ans_query(node,k);
        cout << ans << endl;
    }
    
    
    
}