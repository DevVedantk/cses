#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>subsz;

void subsize(int node,int parent,vector<vector<int>>& adj){
     subsz[node]=1;
     
     for(int child:adj[node]){
         if(parent==child) continue;
         subsize(child,node,adj);
         subsz[node]=subsz[node]+subsz[child];
     }
    
}

int centroid(int node,int parent,vector<vector<int>>& adj,int n){
    
    for(int child:adj[node]){
        if(child==parent) continue;
        if(subsz[child]>n/2) return centroid(child,node,adj,n);
    }
    
    return node;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    subsz.assign(n+1,0);
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    subsize(1,-1,adj);
int ans=centroid(1,-1,adj,n);
    cout << ans << endl;
    
}