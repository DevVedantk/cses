#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
        int n,m;
        cin >> n >> m;
        vector<vector<int>>adj(n+1);
        
        vector<int>indeg(n+1,0);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            indeg[b]++;
        }
        
        vector<int>topo;
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        while(q.size()>0){
            int node=q.front();
            q.pop();
            
            topo.push_back(node);
            for(int child:adj[node]){
                indeg[child]--;
                if(indeg[child]==0) q.push(child);
            }
        }
        
        int MOD=1e9+7;
        vector<int>way(n+1,0);
        way[1]=1;
        
        for(int node:topo){
            for(int child:adj[node]){
                way[child]=(way[child]+way[node])%MOD;
            }
        }
    cout << way[n] << endl;
        
        
    
}