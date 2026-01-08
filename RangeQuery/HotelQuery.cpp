#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>sgt;

void buildt(int i,int l,int r,vector<int>& arr){
    if(l==r){
        sgt[i]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr);
    buildt(2*i+2,mid+1,r,arr);
    sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}
int query(int i,int l,int r,int val){
    if(sgt[i]<val) return 0;
    if(l==r){
        return l+1;
    }
    int mid=(l+r)/2;
    if(sgt[2*i+1]>=val){
        return query(2*i+1,l,mid,val);
    } else return query(2*i+2,mid+1,r,val);
    
}

void update(int i,int l,int r,int idx,int val){
   if(l==r){
       sgt[i]-=val;
       return;
   } 
   int mid=(l+r)/2;
   if(idx<=mid) update(2*i+1,l,mid,idx,val);
   else update(2*i+2,mid+1,r,idx,val);
    sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    sgt.assign(4*n,0);
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildt(0,0,n-1,arr);
    
    for(int i=0;i<m;i++){
        int val;
        cin >> val;
        
        int idx=query(0,0,n-1,val);
        if(idx!=0){
            update(0,0,n-1,idx-1,val);
        }
        cout << idx << " ";
    }
    
}