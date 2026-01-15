#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


struct Node{
  int sum=0;
  int max_pref=INT_MIN;
  int max_suff=INT_MIN;
  int maxarrSum=0;
};
vector<Node>sgt;

Node merge(const Node& left,const Node& right){
    Node res;
    res.sum=left.sum+right.sum;
    
    int prefMax=max(left.max_pref,left.sum+right.max_pref);
   
    res.max_pref=prefMax;
    
    int suffMax=max(right.max_suff,right.sum+left.max_suff);
    res.max_suff=suffMax;
    
    res.maxarrSum=max({left.maxarrSum,right.maxarrSum,left.max_suff+right.max_pref});
    
    return res;
}

void buildt(int i,int l,int r,vector<int>&arr){
    if(l==r){
        sgt[i].max_pref=arr[l];
        sgt[i].max_suff=arr[l];
        sgt[i].maxarrSum=arr[l];
        sgt[i].sum=arr[l];
        return;
    }
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr);
    buildt(2*i+2,mid+1,r,arr);
    sgt[i]=merge(sgt[2*i+1],sgt[2*i+2]);
}

void update(int i,int l,int r,int idx,int val){
     if(l==r){
         sgt[i].max_pref=val;
         sgt[i].max_suff=val;
          sgt[i].maxarrSum=val;
        sgt[i].sum=val;
        return;
     }
     
      int mid=(l+r)/2;
   if(idx<=mid) update(2*i+1,l,mid,idx,val);
   else update(2*i+2,mid+1,r,idx,val);
    sgt[i]=merge(sgt[2*i+1],sgt[2*i+2]);
     
}

Node query(int st,int en,int i,int l,int r){
    if(st>r || l>en) return Node();
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    Node left=query(st,en,2*i+1,l,mid);
    Node right=query(st,en,2*i+2,mid+1,r);
    
    return merge(left,right);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
    
    vector<int>arr(n);
    
    sgt.assign(4*n,Node());
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildt(0,0,n-1,arr);
    
    for(int i=0;i<q;i++){
            int a,b;
            cin >> a >> b;
            a--; b--;
            
            Node ans=query(a,b,0,0,n-1);
            if(ans.maxarrSum<=0){
                cout << 0 << endl;
            } else{
                cout << ans.maxarrSum << endl;
            }
        
    }
}