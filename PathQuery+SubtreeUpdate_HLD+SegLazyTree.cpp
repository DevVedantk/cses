#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int n;
vector<int> sizes,depth,parent,pos,head,heavy,lt;
vector<int> sgt;
vector<int> lazy;
vector<int> value;

int idx=0;


void propogate(int i,int l,int r){
    if(lazy[i]!=0){
         
         //storing max val at sgt
         sgt[i]=sgt[i] + lazy[i];
         
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
    
    sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}


int query(int i,int l,int r,int st,int en){
    propogate(i,l,r);
    
    if(st>r || l>en) return INT_MIN;
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    int left=query(2*i+1,l,mid,st,en);
    int right=query(2*i+2,mid+1,r,st,en);
    
    return max(left,right);
}

void update(int i,int l,int r,int st,int en,int val){
      propogate(i,l,r);
      if(st>r || l>en) return;
      if(l>=st && r<=en){
          lazy[i]+=val;
          propogate(i,l,r);
          return;
      }
      int mid=(l+r)/2;
      
      update(2*i+1,l,mid,st,en,val);
      update(2*i+2,mid+1,r,st,en,val);
      sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}


void dfs(int node,int par,vector<vector<int>>&adj){
    sizes[node]=1;
    parent[node]=par;
    
    for(int child:adj[node]){
        if(child==par) continue;
        
        depth[child]=depth[node] + 1;
        dfs(child,node,adj);
        sizes[node]+=sizes[child];
        
        if(heavy[node]==-1 || sizes[child] > sizes[heavy[node]]){
            heavy[node]=child;
        }
    }
}

void dfsHLD(int node,int par,int chain,vector<vector<int>>&adj){
     head[node]=chain;
     pos[node]=idx;
     lt[idx]=value[node];
     idx++;
     
     if(heavy[node]!=-1){
         dfsHLD(heavy[node],node,chain,adj);
     }
     
     for(int child:adj[node]){
         if(child==par || child==heavy[node]) continue;
         dfsHLD(child,node,child,adj);
     }
}

int queryPath(int a,int b){
    int res=INT_MIN;
    
    while(head[a]!=head[b]){
        if(depth[head[a]] < depth[head[b]]){
            swap(a,b);
        }
        
        int start=head[a];
        res=max(res,query(0,0,n-1,pos[start],pos[a]));
       
       a=parent[start];
    }
      if(depth[a] < depth[b]){
            swap(a,b);
        }
        
       res=max(res,query(0,0,n-1,pos[b],pos[a]));   
      
      return res;
}




signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    
    cin >> n;
    sizes.assign(n,0);
    depth.assign(n,0);
    heavy.assign(n,-1);
    parent.assign(n,-1);
    pos.assign(n,0);
    head.assign(n,0);
    lt.assign(n,0);
    value.assign(n,0);
    
    sgt.assign(4*n,0);
    lazy.assign(4*n,0);
  
  
    //updating on subtree and finding max on path between a to b
    
  //initialing all values are 0
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
   
   buildt(0,0,n-1);
   
   int q;
   cin >> q;
   for(int i=0;i<q;i++){
       string s;
       cin >> s;
       if(s=="add"){
            int node,val;
            cin >> node >> val;
            node--;
            update(0,0,n-1,pos[node],pos[node]+sizes[node]-1,val);
       } else{
             int a,b;
       cin >> a >> b;
       a--;b--;
           cout << queryPath(a,b) << endl;
       }
   }
}