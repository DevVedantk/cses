#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct Node{
  int mine=LLONG_MAX;
  int sum=0;
};

vector<Node>sgt;
vector<int>lazy;

void propogate(int i,int l,int r){
    if(lazy[i]!=0){
            sgt[i].sum+=(r-l+1)*lazy[i];
            sgt[i].mine+=lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
            
        }
            lazy[i]=0;
    }
}

void buildt(int i,int l,int r,vector<int>&arr){
    if(l==r){
        sgt[i].mine=arr[l];
        sgt[i].sum=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    buildt(2*i+1,l,mid,arr);
    buildt(2*i+2,mid+1,r,arr);
    sgt[i].sum=sgt[2*i+1].sum + sgt[2*i+2].sum;
    sgt[i].mine=min(sgt[2*i+1].mine,sgt[2*i+2].mine);
}

void update(int i,int l,int r,int st,int en,int val){
    propogate(i,l,r);
    if(st>r || l>en) return;
    if(l>=st && r<=en){
        lazy[i]+=val;
        propogate(i,l,r);
        return;
    }
    
    int mid=(l+r)/2;
    update(2*i+1,l,mid,st,en,val);
    update(2*i+2,mid+1,r,st,en,val);
   sgt[i].sum=sgt[2*i+1].sum + sgt[2*i+2].sum;
    sgt[i].mine=min(sgt[2*i+1].mine,sgt[2*i+2].mine);
}

Node query(int i,int l,int r,int st,int en){
      propogate(i,l,r);
    if(st>r || l>en) return Node();
    if(l>=st && r<=en) return sgt[i];
    
    int mid=(l+r)/2;
    
    Node left=query(2*i+1,l,mid,st,en);
    Node right=query(2*i+2,mid+1,r,st,en);
    Node res;
    res.sum=left.sum + right.sum;
    res.mine=min(left.mine,right.mine);
    return res;
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

     freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    
    int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    sgt.assign(4*n,Node());
    lazy.assign(4*n,0);
    
    buildt(0,0,n-1,arr);
    for(int i=0;i<q;i++){
        char t;
        cin >> t;
        if(t=='S'){
            int l,r;
            cin >> l >> r;
            l--;r--;
            Node ans=query(0,0,n-1,l,r);
            cout << ans.sum << endl;
        } else if(t=='P'){
             int c,l,r;
            cin >> l >> r >> c;
            l--;r--;
            update(0,0,n-1,l,r,c);
        } else{
             int l,r;
            cin >> l >> r;
            l--;r--;
            Node ans=query(0,0,n-1,l,r);
            cout << ans.mine << endl;
        }
    }
}