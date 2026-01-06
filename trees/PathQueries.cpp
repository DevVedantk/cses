#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;

vector<int>st;
vector<int>endt;
int timer=0;
int maxt=0;
vector<int>segTree;
int n;

void euler_tour(int node,int parent,vector<vector<int>>& adj){
    st[node]=timer++;
    maxt=max(maxt,timer);
    
    for(int child:adj[node]){
        if(child==parent) continue;
        euler_tour(child,node,adj);
    }
    endt[node]=timer++;
    maxt=max(maxt,timer);
}

void update(int idx,int val,int i=0,int l=0,int r=2*n-1){
    if(l==r){
       segTree[i]=val;
       return;
    }
    
    int mid=(l+r)/2;
    if(idx<=mid) update(idx,val,2*i+1,l,mid);
    else update(idx,val,2*i+2,mid+1,r);
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

int query(int st,int en,int i=0,int l=0,int r=2*n-1){
    if(st>r || en<l) return 0;
    if(l>=st && r<=en) return segTree[i];
    
    int mid=(l+r)/2;
    
    
    return query(st,en,2*i+1,l,mid)+query(st,en,2*i+2,mid+1,r);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int q;
    cin >> n >> q;
    st.assign(n+1,0);
    endt.assign(n+1,0);
    segTree.assign(8*n,0);
    
    vector<int>val(n+1,0);
    
    for(int i=1;i<=n;i++) cin >> val[i];
    
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    euler_tour(1,-1,adj);
    
    for(int i=1;i<=n;i++){
        update(st[i],val[i]);
         update(endt[i],-val[i]);
    }

    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int idx,val;
            cin >> idx >> val;
            update(st[idx],val);
            update(endt[idx],-val);
        } else{
            int node;
            cin >> node;
            cout << query(st[1],endt[node]-1) << endl;
        }
    }
    
}