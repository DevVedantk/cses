#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int dia=0;

int solve(vector<vector<int>>& adj,int node,int parent){
    int dep=-1,secdep=-1;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        int childht=solve(adj,child,node);
        if(childht>=dep){
            secdep=dep;
            dep=childht;
        } else if(childht>=secdep) secdep=childht;
    }
    if((dep+secdep+2)>dia) dia=dep+secdep+2;
    dep+=1;
    return dep;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n-1;i++){
        int e1,e2;
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }
    solve(adj,1,-1);
    cout << dia << endl;
}