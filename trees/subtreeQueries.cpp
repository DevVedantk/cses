#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>start;
vector<int>endt;
vector<int>fen;
int maxt=0;

int timer = 0;

void euler_tour(int node, int par, vector<vector<int>>& adj){
    start[node] = ++timer;
    maxt = timer;
    for(int child: adj[node]){
        if(child == par) continue;
        euler_tour(child, node, adj);
    }
    endt[node] = timer;
}

void update(int idx,int x,int n){
      while(idx<=n){
          fen[idx]+=x;
          idx+=(idx&-idx);
      }
}

int sum(int idx){
    int s=0;
    while(idx>0){
        s+=fen[idx];
        idx-=(idx&-idx);
    }
    return s;
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<int>val(n+1);
    for(int i=1;i<=n;i++) cin >> val[i];
    
    
    start.assign(n+1,0);
    endt.assign(n+1,0);
   
    
    
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    euler_tour(1,-1,adj);
    
    vector<int>range(maxt+1,0);
    
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[start[i]]=i;
    }
    
    for(int i=1;i<=maxt;i++){
        if(mp.find(i)!=mp.end())
         range[i]=mp[i]; 
    }
     fen.assign(maxt+1,0);
     
for(int i = 1; i <= n; i++){
    update(start[i], val[i], maxt);
}
     
    for(int i=0;i<q;i++){
         int type;
         cin >> type;
        if(type == 1){
    int node, x;
    cin >> node >> x;
    int diff = x - val[node];
    val[node] = x;
    update(start[node], diff, maxt);
}
else{
    int node;
    cin >> node;
    cout << sum(endt[node]) - sum(start[node]-1) << endl;
}
    }
    
    
}