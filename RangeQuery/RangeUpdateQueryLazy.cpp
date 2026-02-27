#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>sgt;
vector<int>lazy;

void propogate(int i,int l,int r){
    if(lazy[i]!=0){
        sgt[i]+=(r-l+1)*lazy[i];
        
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
}

void update(int st,int en,int i,int l,int r,int val){
      propogate(i,l,r);
      
      if(st>r || l>en) return;
      if(l>=st && r<=en){
            lazy[i]+=val;
            propogate(i,l,r);
            return;
      }
    
    int mid=(l+r)/2;
    
    update(st,en,2*i+1,l,mid,val);
    update(st,en,2*i+2,mid+1,r,val);
    sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

int query(int i,int l,int r,int idx){
     propogate(i,l,r);
    if(l==r){
        return sgt[i];
    }
    
    int mid=(l+r)/2;
    
    if(idx<=mid) return query(2*i+1,l,mid,idx);
    else return query(2*i+2,mid+1,r,idx);
}

void buildt(int i,int l,int r,vector<int>&arr){
    if(l==r){
        sgt[i]=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    
    buildt(2*i+1,l,mid,arr);
    buildt(2*i+2,mid+1,r,arr);
    sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    
    sgt.assign(4*n,0);
    lazy.assign(4*n,0);
    
    buildt(0,0,n-1,arr);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int a,b,u;
            cin >> a >> b >> u;
            a--;b--;
            update(a,b,0,0,n-1,u);
        } else{
          int k;
          cin >> k;
          k--;
          cout << query(0,0,n-1,k) << endl;
        }
    }
    
}

