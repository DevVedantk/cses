#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vector<int>deg(n+1,0);
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }
    
    vector<int>res;
    while(q.size()>0){
        int node=q.front();
        q.pop();
        res.push_back(node);
        
        for(int child:adj[node]){
            deg[child]--;
            if(deg[child]==0) q.push(child);
        }
    }
    
    if(res.size()!=n) cout << "IMPOSSIBLE" << endl;
    else {
        for(int ele:res) cout << ele << " ";
    }
    
    
}