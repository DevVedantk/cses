#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
   vector<tuple<int,int,int>>edges;
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    
    vector<int>dist(n+1,0);
    vector<int>relaxant(n+1,-1);
    
    int x=-1;
    for(int i=0;i<n;i++){
        x=-1;
        for(auto [u,v,wt]:edges){
            if((dist[u]+wt) < dist[v] ){
                dist[v]=dist[u]+wt;
                relaxant[v]=u;
                x=v;
            }
        }
    }
    
    if(x==-1) cout << "NO" << endl;
    else{
        for(int i=0;i<n;i++){
            x=relaxant[x];
        }
        
        int curr=x;
        vector<int>cycle;
       while(true){
           cycle.push_back(curr);
           if(curr==x && cycle.size()>1) break;
           curr=relaxant[curr];
       }
       
       reverse(cycle.begin(),cycle.end());
       cout << "YES" << endl;
       for(int ele:cycle) cout << ele << " ";
       
    }
    
}