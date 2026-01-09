#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>sgt;
vector<int>lazy_add;
vector<int>lazy_set;

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


void push(int i,int l,int r){
    
       if(lazy_set[i]!=0){
        sgt[i]=((r-l+1)*lazy_set[i]);
        if(l!=r){
            lazy_set[2*i+1]=lazy_set[i];
            lazy_set[2*i+2]=lazy_set[i];
            
            lazy_add[2*i+1] = 0;
            lazy_add[2*i+2] = 0;
        }
        lazy_set[i]=0;
    }
    
    if(lazy_add[i]!=0){
        sgt[i]+=((r-l+1)*lazy_add[i]);
        if(l!=r){
            lazy_add[2*i+1]+=lazy_add[i];
            lazy_add[2*i+2]+=lazy_add[i];
        }
        lazy_add[i]=0;
    }
    
    
}


int query(int st,int en,int i,int l,int r){
    push(i,l,r);
    if(st>r || en<l) return 0;
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    return query(st,en,2*i+1,l,mid)+query(st,en,2*i+2,mid+1,r); 
}


void update(int st,int en,int i,int l,int r,int val,bool type){
      push(i,l,r);
      if(st>r || en<l) return;
      
       if(l>=st && r<=en){
          if(type==1) lazy_add[i]+=val;
          else{
              lazy_set[i]=val;
             
          }
           push(i,l,r);
           return;
       }
       
         int mid=(l+r)/2;
         update(st,en,2*i+1,l,mid,val,type);
         update(st,en,2*i+2,mid+1,r,val,type);
      sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    lazy_add.assign(4*n,0);
    lazy_set.assign(4*n,0);
    // lazy2.assign(4*n,0);
    sgt.assign(4*n,0);
    buildt(0,0,n-1,arr);
    
    
    for(int i=0;i<q;i++){
        int t,a,b,x;
        cin >> t;
        if(t==1){
           cin >> a >> b >> x;
           update(a-1,b-1,0,0,n-1,x,1);
        } else if(t==2){
             cin >> a >> b >> x;
           update(a-1,b-1,0,0,n-1,x,0);
        } else{
            cin >> a >> b;
            cout << query(a-1,b-1,0,0,n-1) << endl;
        }
    }
    
    
}