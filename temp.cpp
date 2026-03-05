#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


vector<int>xors;
vector<int>lvl;

int timer=0;
 
vector<int>start;
vector<int>ens;
void euler_tour(int node,int parent,vector<vector<int>>&adj){
    start[node]=timer++;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        euler_tour(child,node,adj);
    }
    ens[node]=timer++;
}
 
vector<int>sgt;
 
void update(int i,int l,int r,int idx,int val){
    if(l==r){
        sgt[i]=val;
        return;
    }
    
    int mid=(l+r)/2;
    if(idx<=mid) update(2*i+1,l,mid,idx,val);
    else update(2*i+2,mid+1,r,idx,val);
    
    sgt[i]=sgt[2*i+1] ^ sgt[2*i+2];
}
 
int query(int i,int l,int r,int st,int en){
    if(st>r || l>en) return 0;
    
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    
    int left=query(2*i+1,l,mid,st,en);
    int right=query(2*i+2,mid+1,r,st,en);
    
    return left^right;
}


void dfs(int node,int parent,vector<vector<int>>&adj,int xr,vector<int>&val,int level){
    xors[node]=xr;
    lvl[node]=level;
    
    for(int child:adj[node]){
        if(child==parent) continue;
        dfs(child,node,adj,xr^val[child],val,level+1);
    }

}

int up[100001][20];

void binary_lifting(int node,int parent,vector<vector<int>>&adj){
    
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

int up_node(int u,int jump){
    if(u==-1 || jump==0) return u;
    
    for(int i=19;i>=0;i--){
        if((1<<i)<=jump){
            return up_node(up[u][i],jump-(1<<i));
        }
    }
    return -1;
}


int lca(int u,int v){
    if(lvl[u]<lvl[v]) swap(u,v);
    
    int jump=lvl[u]-lvl[v];
    u=up_node(u,jump);
    
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    
    return up_node(u,1);
}

signed main(){
  freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    vector<int>val(n+1);
    for(int i=1;i<=n;i++) cin >> val[i];
    
    xors.assign(n+1,0);
    lvl.assign(n+1,0);
    
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,-1,adj,val[1],val,1);
    
    binary_lifting(1,-1,adj);
    
    sgt.assign(8*n,0);
    start.assign(n+1,0);
    ens.assign(n+1,0);
    
    euler_tour(1,-1,adj);
    
    for(int i=1;i<=n;i++){
        update(0,0,2*n-1,start[i],val[i]);
        update(0,0,2*n-1,ens[i],val[i]);
    }
    
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
       if(t==1){
    int node,x;
    cin >> node >> x;

    int diff = val[node] ^ x;

    // toggle both occurrences
    int cur1 = query(0,0,2*n-1,start[node],start[node]);
    int cur2 = query(0,0,2*n-1,ens[node],ens[node]);

    update(0,0,2*n-1,start[node],cur1 ^ diff);
    update(0,0,2*n-1,ens[node],cur2 ^ diff);

    val[node] = x;
}
else{
           int a,b;
           cin >> a >> b;
           int lca_ab=lca(a,b);
            int xor1 = query(0,0,2*n-1,0,start[a]);
          int xor2 = query(0,0,2*n-1,0,start[b]);
             int ans = xor1 ^ xor2 ^ val[lca_ab];
           cout << ans << endl;
        }
    }

    
    
    
    
    
}