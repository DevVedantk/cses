#include <bits/stdc++.h>
#define int long long
#define endl '\n'
 
using namespace std;
vector<int>sgt1;
vector<int>sgt2;
 
void buildt(int i,int l,int r,vector<int>&arr,vector<int>&sgt){
    if(l==r){
        sgt[i]=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr,sgt);
    buildt(2*i+2,mid+1,r,arr,sgt);
    
    sgt[i]=min(sgt[2*i+1],sgt[2*i+2]);
}
 
void update(int i,int l,int r,int idx,int val,vector<int>&sgt){
    if(l==r){
        sgt[i]=val;
        return;
    }
    int mid=(l+r)/2;
    
    if(idx<=mid) update(2*i+1,l,mid,idx,val,sgt);
    else update(2*i+2,mid+1,r,idx,val,sgt);
     sgt[i]=min(sgt[2*i+1],sgt[2*i+2]);
}
 
int query(int st,int en,int i,int l,int r,vector<int>&sgt){
    
    if(st>r || l>en) return INT_MAX;
    
    if(l>=st && r<=en) return sgt[i];
    int mid=(l+r)/2;
    
    int left=query(st,en,2*i+1,l,mid,sgt);
    int right=query(st,en,2*i+2,mid+1,r,sgt);
    
    return min(left,right);
}
 
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int>front(n);
    for(int i=0;i<n;i++){
        front[i]=i+arr[i];
    }
    vector<int>back(n);
    for(int i=0;i<n;i++) back[i]=arr[i]-i;
    
    sgt1.assign(4*n,0);
    sgt2.assign(4*n,0);
    
    buildt(0,0,n-1,back,sgt1);
    buildt(0,0,n-1,front,sgt2);
    
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int idx,x;
            cin >> idx >> x;
            idx--; //handle 0 based
             arr[idx]=x;
             
             update(0,0,n-1,idx,arr[idx]-idx,sgt1);
             update(0,0,n-1,idx,arr[idx]+idx,sgt2);
             
        } else{
            int idx;
            cin >> idx;
            idx--; // handle 0 based indexing
            int ans=arr[idx];
            int minleft=query(0,idx-1,0,0,n-1,sgt1);
            int minright=query(idx+1,n-1,0,0,n-1,sgt2);
            ans=min({ans,idx+minleft,minright-idx});
            cout << ans << endl;
        }
    }
    
    
    
}