#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


struct Node{
  int sum=0;
  int max_prefix=0;
};
vector<Node>sgt;

Node merge(const Node& left,const Node& right){
    Node res;
    int total=left.sum+right.sum;
    int prefMax=max({left.max_prefix,left.sum+right.max_prefix});
    res.sum=total;
    res.max_prefix=prefMax;
    return res;
}

void buildt(int i,int l,int r,vector<int>&arr){
    if(l==r){
        sgt[i].max_prefix=arr[l];
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
         sgt[i].max_prefix=val;
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
        int t;
        cin >> t;
        if(t==1){
            int idx,val;
            cin >> idx >> val;
            idx--;
            update(0,0,n-1,idx,val);
        } else{
            int a,b;
            cin >> a >> b;
            a--;b--;
            Node ans=query(a,b,0,0,n-1);
            if(ans.max_prefix<=0){
                cout << 0 << endl;
            } else{
                cout << ans.max_prefix << endl;
            }
        }
    }
}