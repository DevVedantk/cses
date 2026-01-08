#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>sgt;

void buildt(int i,int l,int r){
    if(l==r){
        sgt[i]=0;
        return;
    }
    
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid);
    buildt(2*i+2,mid+1,r);
    sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

void update(int i,int l,int r,int pos,int val){
     if(l==r){
         sgt[i]+=val;
         return;
     } 
     
     int mid=(l+r)/2;
     
    if(pos<=mid) update(2*i+1,l,mid,pos,val);
    else update(2*i+2,mid+1,r,pos,val);
    sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

int query(int i,int l,int r,int st,int en){
     if(st>r || l>en) return 0;
     
     if(l>=st && r<=en) return sgt[i];
     int mid=(l+r)/2;
   int left=query(2*i+1,l,mid,st,en);
    int right=query(2*i+2,mid+1,r,st,en);
     return left+right;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    sgt.assign(4*n,0);
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildt(0,0,n-1);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
           int a,b,u;
           cin >> a >> b >> u;
           a--;b--;
           update(0,0,n-1,a,u);
          if(b+1<n) update(0,0,n-1,b+1,-u);
        } else{
            int k;
            cin >> k;
            k--;
            int sum=query(0,0,n-1,0,k);
            cout << sum + arr[k] << endl;
        }
    }
    
}