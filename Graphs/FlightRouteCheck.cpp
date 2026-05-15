#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>>adj(n+1);
     vector<vector<int>>rev(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    
    vector<bool>vis(n+1,false);
    queue<int>q;
    q.push(1);
     vis[1]=true;
    while(q.size()>0){
        int node=q.front();
        q.pop();
    
    
    for(int child:adj[node]){ 
        if(!vis[child]){
             vis[child]=true;
            q.push(child);
        }    
    }
 }
 
 bool ch=true;
 for(int i=1;i<=n;i++){
     if(vis[i]==false){
         ch=false;
         cout << "NO" << endl;
         cout << 1 << " " << i << endl;
         break;
     }
 }
 if(ch){
     vis.assign(n+1,false);
    q.push(1);
    vis[1]=true;
    
    while(q.size()>0){
        int node=q.front();
        q.pop();
   
    
    for(int child:rev[node]){ 
        if(!vis[child]){
             vis[child]=true;
            q.push(child);
        }    
    }
 }
 
  for(int i=1;i<=n;i++){
     if(vis[i]==false){
         ch=false;
         cout << "NO" << endl;
         cout << i << " " << 1 << endl;
         break;
     }
  }
     
     if(ch) cout << "YES" << endl;
 
 
 
    
}
}