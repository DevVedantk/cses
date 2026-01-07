#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int n;

vector<int>sgt;

void buildT(int i,int l,int r,vector<int>& arr){
    if(l==r){
        sgt[i]=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    buildT(2*i+1,l,mid,arr);
    buildT(2*i+2,mid+1,r,arr);
    sgt[i]=min(sgt[2*i+1],sgt[2*i+2]);
}

int query(int st,int en,int i=0,int l=0,int r=n-1){
      if(st>r || en<l) return INT_MAX;
      if(l>=st && r<=en) return sgt[i];
      
      int mid=(l+r)/2;
      
     return min(query(st,en,2*i+1,l,mid),query(st,en,2*i+2,mid+1,r));
}

void update(int idx,int val,int i=0,int l=0,int r=n-1){
     if(l==r){
         sgt[i]=val;
         return;
     }
     
     int mid=(l+r)/2;
     
     if(idx<=mid) update(idx,val,2*i+1,l,mid);
     else update(idx,val,2*i+2,mid+1,r);
    sgt[i]=min(sgt[2*i+1],sgt[2*i+2]);
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int q;
    cin >> n >> q;
    sgt.assign(4*n,0);
    
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildT(0,0,n-1,arr);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int idx,val;
            cin >> idx >> val;
            update(idx-1,val);
        } else{
            int a,b;
            cin >> a >> b;
            cout << query(a-1,b-1) << endl;
        }
    }
}