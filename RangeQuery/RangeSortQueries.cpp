#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
struct Node{
  int sum=0;
  int val=-1;
};
vector<Node>sgt1;
vector<Node>sgt2;
vector<int>lazy1;
vector<int>lazy2;

void propogate(int i,int l,int r,vector<Node>&sgt,vector<int>&lazy){
     
     if(lazy[i]!=-1){
         sgt[i].val=lazy[i];
         sgt[i].sum=(r-l+1)*lazy[i];
         
         if(l!=r){
             lazy[2*i+1]=lazy[i];
             lazy[2*i+2]=lazy[i];
         }
         lazy[i]=-1;
     }
}

void buildt(int i,int l,int r,vector<int>&arr,vector<Node>&sgt){
    if(l==r){
        sgt[i].val=arr[l];
        sgt[i].sum=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr,sgt);
    buildt(2*i+2,mid+1,r,arr,sgt);
    sgt[i].sum=sgt[2*i+1].sum+sgt[2*i+2].sum;
}


void update(int i,int l,int r,int st,int en,int val,vector<int>&lazy,vector<Node>&sgt){
    propogate(i,l,r,sgt,lazy);
    if(st>r || l>en) return;
    if(l>=st && r<=en){
        lazy[i]=val;
        propogate(i,l,r,sgt,lazy);
        return;
    }
    
    int mid=(l+r)/2;
    update(2*i+1,l,mid,st,en,val,lazy,sgt);
    update(2*i+2,mid+1,r,st,en,val,lazy,sgt);
    sgt[i].sum=sgt[2*i+1].sum+sgt[2*i+2].sum;
}

int query2(int i,int l,int r,int st,int en,vector<Node>&sgt,vector<int>&lazy){
    propogate(i,l,r,sgt,lazy);
    if(st>r || l>en) return 0;
    if(l>=st && r<=en) return sgt[i].sum;
    
    int mid=(l+r)/2;
    
    int left=query2(2*i+1,l,mid,st,en,sgt,lazy);
    int right=query2(2*i+2,mid+1,r,st,en,sgt,lazy);
    return left+right;
}

int query(int i,int l,int r,int idx,vector<Node>&sgt,vector<int>&lazy){
    propogate(i,l,r,sgt,lazy);
    if(l==r) return sgt[i].val;
    
    int mid=(l+r)/2;
    if(idx<=mid) return query(2*i+1,l,mid,idx,sgt,lazy);
   else  return query(2*i+2,mid+1,r,idx,sgt,lazy);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q,x;
    
    cin >> n >> q >> x;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    vector<int>a(n);
    vector<int>b(n);
    
    sgt1.assign(4*n,Node());
    sgt2.assign(4*n,Node());
    lazy1.assign(4*n,-1);
    lazy2.assign(4*n,-1);
    
    for(int i=0;i<n;i++){
        if(arr[i]>=x) a[i]=1;
        else a[i]=0;
        
        if(arr[i]>=x+1) b[i]=1;
        else b[i]=0;
    }
    
    buildt(0,0,n-1,a,sgt1);
    buildt(0,0,n-1,b,sgt2);

    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int l,r;
            cin >> l >> r;
            l--;r--;
            //increasing sorting
            int sum1=query2(0,0,n-1,l,r,sgt1,lazy1);
            int sum2=query2(0,0,n-1,l,r,sgt2,lazy2);
            
            int len=r-l+1;
            int zero1=len-sum1;
            int zero2=len-sum2;
            update(0,0,n-1,l,l+zero1-1,0,lazy1,sgt1);
            update(0,0,n-1,l+zero1,r,1,lazy1,sgt1);
            
            update(0,0,n-1,l,l+zero2-1,0,lazy2,sgt2);
            update(0,0,n-1,l+zero2,r,1,lazy2,sgt2);
        } else{
             int l,r;
            cin >> l >> r;
            l--;r--;
            //decreasing sorting
            int len=r-l+1;
            
            int sum1=query2(0,0,n-1,l,r,sgt1,lazy1);
           int sum2=query2(0,0,n-1,l,r,sgt2,lazy2);
           
         
        
            update(0,0,n-1,l,l+sum1-1,1,lazy1,sgt1);
            update(0,0,n-1,l+sum1,r,0,lazy1,sgt1);
            
            update(0,0,n-1,l,l+sum2-1,1,lazy2,sgt2);
            update(0,0,n-1,l+sum2,r,0,lazy2,sgt2);
        }
    } 
    
    for(int i=0;i<n;i++){
        int v1=query(0,0,n-1,i,sgt1,lazy1);
        int v2=query(0,0,n-1,i,sgt2,lazy2);
        if(v1!=v2){
            cout << i+1 << endl;
            break;
        }
        
    }
    
}