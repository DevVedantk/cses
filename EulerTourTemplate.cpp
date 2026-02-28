#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>start;
vector<int>ending;

int timer=0;
void euler_tour(int node,int parent,vector<vector<int>>&adj){
       start[node]=timer++;
       
       for(int child:adj[node]){
           if(child==parent) continue;
           euler_tour(child,node,adj);
       }
       
       ending[node]=timer;
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int>sgt;

void buildt(int i,int l,int r,vector<int>&arr){
    if(l==r){
        sgt[i]=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr);
    buildt(2*i+2,mid+1,r,arr);
    sgt[i]=gcd(sgt[2*i+1],sgt[2*i+2]);
}

void update(int i,int l,int r,int idx,int val){
    if(l==r){
        sgt[i]=val;
        return;
    }
    
    int mid=(l+r)/2;
    if(idx<=mid) update(2*i+1,l,mid,idx,val);
    else update(2*i+2,mid+1,r,idx,val);
     sgt[i]=gcd(sgt[2*i+1],sgt[2*i+2]);
}

int query(int i,int l,int r,int st,int en){
     if(st>r || l>en) return 0;
     if(l>=st && r<=en) return sgt[i];
     int mid=(l+r)/2;
     
     int left=query(2*i+1,l,mid,st,en);
     int right=query(2*i+2,mid+1,r,st,en);
     
     return gcd(left,right);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<int>values(n);
    for(int i=0;i<n;i++) cin >> values[i];
    
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        // 0th node starting
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    start.assign(n,0);
    ending.assign(n,0);
    
    euler_tour(0,-1,adj);
    
    vector<int>euler_arr(timer);
    
    for(int i=0;i<n;i++){
        euler_arr[start[i]]=values[i];
    }
    
    sgt.assign(4*n,0);
    buildt(0,0,n-1,euler_arr);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int idx,val;
            cin >> idx >> val;
            idx--;
            update(0,0,n-1,start[idx],val);
        } else{
            int node;
            cin >> node;
            node--; // 0 based
            int l=start[node] , r=ending[node]-1;
            
            cout << query(0,0,n-1,l,r) << endl; 
        }
    }
}