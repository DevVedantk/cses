#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>sgt;

void buildt(int i,int l,int r){
    if(l==r) {
        sgt[i]=1;
        return;
    }
    
    int mid=(l+r)/2;
    
    buildt(2*i+1,l,mid);
    buildt(2*i+2,mid+1,r);
    
    sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

void update(int i,int l,int r,int k){
    if(l==r){
        sgt[i]=0;
        return;
    }
    
    int mid=(l+r)/2;
    if(sgt[2*i+1]>=k) update(2*i+1,l,mid,k);
    else update(2*i+2,mid+1,r,k-sgt[2*i+1]);
  sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

int query(int i,int l,int r,int k,vector<int>&arr){
    if(l==r){
        return arr[l];
    }
    
    int mid=(l+r)/2;
     if(sgt[2*i+1]>=k) return query(2*i+1,l,mid,k,arr);
    else return query(2*i+2,mid+1,r,k-sgt[2*i+1],arr);
    
}



signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    sgt.assign(4*n,0);
    
    vector<int>pos(n);
    for(int i=0;i<n;i++) cin >> pos[i];
    
    buildt(0,0,n-1);
    for(int i=0;i<n;i++){
        int idx=pos[i];
     
       cout << query(0,0,n-1,idx,arr) << " ";
       update(0,0,n-1,idx);
    }
    
    
}