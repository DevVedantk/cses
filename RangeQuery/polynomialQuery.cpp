#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct lazy_node{
  int a,d;    
};

vector<int>sgt;
vector<lazy_node>lazy;

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

int ap_sum(int a,int d,int n){
    return n*(2*a+(n-1)*d)/2;
}

void apply(int i,int l,int r,int a,int d){
    int n=r-l+1;
    sgt[i]+=ap_sum(a,d,n);
    lazy[i].a+=a;
    lazy[i].d+=d;
}

void push(int i,int l,int r){
   if(lazy[i].a==0 && lazy[i].d==0) return;
    
    if(l==r){
        lazy[i]={0,0};
        return;
    }    
    
    int mid=(l+r)/2;
    int leftlen=mid-l+1;
    //same a and d to left
    apply(2*i+1,l,mid,lazy[i].a,lazy[i].d);
    
    int new_a=lazy[i].a + leftlen*lazy[i].d;
     apply(2*i+2,mid+1,r,new_a,lazy[i].d);
     lazy[i]={0,0};
}

void update(int i,int l,int r,int st,int en){
    if(st>r || l>en) return;
    if(l>=st && r<=en){
        int a=l-st+1;
        apply(i,l,r,a,1);
        return;
    }
    push(i,l,r);
    
     int mid=(l+r)/2;
     
     update(2*i+1,l,mid,st,en);
     update(2*i+2,mid+1,r,st,en);
     sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

int query(int i,int l,int r,int st,int en){
       if(st>r || l>en) return 0;
       if(l>=st && r<=en) return sgt[i];
       
         push(i,l,r);
    
       int mid=(l+r)/2;
       int left=query(2*i+1,l,mid,st,en);
       int right=query(2*i+2,mid+1,r,st,en);
       
       return left+right;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    
    vector<int>arr(n);
    
    sgt.assign(4*n,0);
    lazy.assign(4*n,{0,0});
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildt(0,0,n-1,arr);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int a,b;
            cin >> a >> b;
            a--;b--;
            update(0,0,n-1,a,b);
        } else{
             int a,b;
             cin >> a >> b;
             a--;b--;
             cout << query(0,0,n-1,a,b) << endl;
        }
    }
    
}