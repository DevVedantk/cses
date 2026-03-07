#include <bits/stdc++.h>
#define int long long
#define endl '\n'
 
using namespace std;
 
 
vector<int>sgt;
vector<int> sizes,parent,depth,pos,head,heavy,lt,val;
vector<int>edgeToNode;
 
int idx=1;
int n;
 
struct Node{
    int src;
    int nbr;
    int cost;
    int idx;
    
    Node(int sr,int nb,int c,int i){
        src=sr;
        nbr=nb;
        cost=c;
        idx=i;
    }
};
 
void buildt(int i,int l,int r){
    if(l==r){
        sgt[i]=lt[l];
        return;
    }
    
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid);
    buildt(2*i+2,mid+1,r);
    
    sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}
 
int query(int i,int l,int r,int st,int en){
    if(st>r || l>en) return INT_MIN;
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    int left=query(2*i+1,l,mid,st,en);
    int right=query(2*i+2,mid+1,r,st,en);
    
    return max(left,right);
}
 
void update(int i,int l,int r,int idx,int val){
    if(l==r){
        sgt[i]=val;
        return;
    }
    
    int mid=(l+r)/2;
    if(idx<=mid) update(2*i+1,l,mid,idx,val);
    else update(2*i+2,mid+1,r,idx,val);
     sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}
 
 
void dfs(int node,int par,vector<vector<Node>>&adj){
    sizes[node]=1;
    parent[node]=par;
    
    for(const Node &e : adj[node]){
        if(e.nbr==par) continue;
        
        depth[e.nbr]=depth[node] + 1;
        edgeToNode[e.idx]=e.nbr;
        val[e.nbr]=e.cost;
        dfs(e.nbr,node,adj);
        
        sizes[node]+=sizes[e.nbr];
        
        if(heavy[node]==-1 || sizes[e.nbr] > sizes[heavy[node]]){
            heavy[node]=e.nbr;
        }
    }
}
 
void dfsHLD(int node,int par,int chain,vector<vector<Node>>&adj){
    head[node]=chain;
    lt[idx]=val[node];
    pos[node]=idx;
    idx++;
    
    if(heavy[node]!=-1){
        dfsHLD(heavy[node],node,chain,adj);
    }
    
    for(const Node &e : adj[node]){
        if(e.nbr==par || e.nbr==heavy[node]) continue;
        dfsHLD(e.nbr,node,e.nbr,adj);
    }
}
 
 
 
 
int queryPath(int a,int b){
      
      int res=INT_MIN;
      
      while(head[a]!=head[b]){
          if(depth[head[a]] < depth[head[b]]){
              swap(a,b);
          }
          
          int start=head[a];
          res=max(res,query(0,1,n,pos[start],pos[a]));
          a=parent[start];
      }
      
       if(depth[a] < depth[b]){
              swap(a,b);
          }
          //not include lca in edge updating problem 
          //here b is lca
          
          res=max(res,query(0,1,n,pos[b]+1,pos[a]));
          return res;
}
 
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t-- >0){
        cin >> n;
        
        idx=1;
        pos.assign(n+1,0);
        val.assign(n+1,0);
        parent.assign(n+1,-1);
        heavy.assign(n+1,-1);
        head.assign(n+1,0);
        lt.assign(n+1,0);
        sizes.assign(n+1,0);
        depth.assign(n+1,0);
        edgeToNode.assign(n,0);
        
         vector<vector<Node>> adj(n+1);
        
        for(int i=1;i<n;i++){
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(Node(a,b,c,i));
            adj[b].push_back(Node(b,a,c,i));
        }
        
        
        dfs(1,-1,adj);
        
        sgt.assign(4*n,0);
        
        dfsHLD(1,-1,1,adj);
        
        buildt(0,1,n);
        
        while(true){
            string s;
            cin >> s;
            if(s=="DONE") break;
            if(s=="CHANGE"){
                int i,val;
                cin >> i >> val;
                int node=edgeToNode[i];
                update(0,1,n,pos[node],val);
            } else{
                int a,b;
                cin >> a >> b;
                cout << queryPath(a,b) << endl;
            }
        }
        
    }
} 