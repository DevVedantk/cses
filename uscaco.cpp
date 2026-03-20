#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n;
vector<int>val;
vector<int> sizes,head,lt,pos,heavy,depth,parent;
vector<int>sgt,lazy;
int idx=0;


void dfs(int node,int par,vector<vector<int>>&adj){
    parent[node]=par;
    sizes[node]=1;
    
    for(int child:adj[node]){
        if(child==par) continue;
        
        depth[child]=depth[node]+1;
        dfs(child,node,adj);
        
        sizes[node]+=sizes[child];
        
        if(heavy[node]==-1 || sizes[child]>sizes[heavy[node]]){
            heavy[node]=child;
        }
    }
}

void dfsHLD(int node,int par,int chain,vector<vector<int>>&adj){
    head[node]=chain;
    pos[node]=idx;
    lt[idx]=val[node];
    idx++;
    
    if(heavy[node]!=-1){
        dfsHLD(heavy[node],node,chain,adj);
    }
    
    for(int child:adj[node]){
        if(child==par || child==heavy[node])  continue;
        dfsHLD(child,node,child,adj);
    }
}
void propogate(int i,int l,int r){
    if(lazy[i]!=0){
        sgt[i]+=lazy[i];
        
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
}


void buildt(int i,int l,int r){
    if(l==r){
        sgt[i]=lt[l];
        return;
    }
    int mid=(l+r)/2;
    
    buildt(2*i+1,l,mid);
    buildt(2*i+2,mid+1,r);
    
    sgt[i]=max(sgt[2*i+1], sgt[2*i+2]);
}

int query(int i,int l,int r,int st,int en){
    propogate(i,l,r);
    if(st>r|| l>en) return 0;
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    
    int left=query(2*i+1,l,mid,st,en);
    int right=query(2*i+2,mid+1,r,st,en);
    return  max(left,right);
}

void updateRange(int i,int l,int r,int st,int en,int val){
    propogate(i,l,r);
    if(st>r || l>en) return;
    if(l>=st && r<=en){
        lazy[i]+=val;
        propogate(i,l,r);
        return;
    }
    
    int mid=(l+r)/2;
    updateRange(2*i+1,l,mid,st,en,val);
    updateRange(2*i+2,mid+1,r,st,en,val);
    sgt[i]=max(sgt[2*i+1], sgt[2*i+2]);
    
}



void updatePath(int a,int b,int val){
    
    while(head[a]!=head[b]){
        if(depth[head[a]] < depth[head[b]]){
            swap(a,b);
        }
        
       int start=head[a];
       updateRange(0,0,n-1,pos[start],pos[a],val);
       
       a=parent[start];
    }
    
    if(depth[a] < depth[b]) swap(a,b);
     updateRange(0,0,n-1,pos[b],pos[a],val);
     
}

int Pathquery(int a,int b){
     int res=0;
    
     while(head[a]!=head[b]){
        if(depth[head[a]] < depth[head[b]]){
            swap(a,b);
        }
        
       int start=head[a];
      res+=query(0,0,n-1,pos[start],pos[a]);
       
       a=parent[start];
    }
    
    if(depth[a] < depth[b]) swap(a,b);
    res+=query(0,0,n-1,pos[b],pos[a]);
    return res;
}

signed main(){
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> n >> q;
    val.assign(n,0);
    

    //just change lazy logic and pathquery logic else same
    //work for range update on complete path from a to b and query on path from a to b
    //time complexity is O(logn*logn) because of logn for path and logn for segment tree query and update
    //overall complexity is O((n+q)*logn*logn)
    
    
    
    sizes.assign(n,0);
    parent.assign(n,-1);
    pos.assign(n,0);
    heavy.assign(n,-1);
    depth.assign(n,0);
      lt.assign(n,0);
    head.assign(n,0);
    
    vector<vector<int>>adj(n);
    
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0,-1,adj);
    
  
    
    dfsHLD(0,-1,0,adj);
    
   
    sgt.assign(4*n,0);
    lazy.assign(4*n,0);
    buildt(0,0,n-1);
    
    for(int i=0;i<q;i++){
            int a,b;
            cin >> a >> b;
            a--;b--;
            updatePath(a,b,1);
    }
    
  cout << query(0,0,n-1,0,n-1) << endl;    
    
    
}