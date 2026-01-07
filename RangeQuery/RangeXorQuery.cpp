#include <bits/stdc++.h>
#define int long long
 
#define endl '\n'
 
using namespace std;
 
vector<int>sgt;
int n;
 
void buildt(int i,int l,int r,vector<int>& arr){
   if(l==r){
      sgt[i]=arr[l];
      return;
   }
   
   int mid=(l+r)/2;
   buildt(2*i+1,l,mid,arr);
   buildt(2*i+2,mid+1,r,arr);
   
   sgt[i]=sgt[2*i+1]^sgt[2*i+2];
}
 
int query(int st,int en,int i=0,int l=0,int r=n-1){
      if(st>r || en<l) return 0;
      if(l>=st && r<=en) return sgt[i];
      
      int mid=(l+r)/2;
      int left=query(st,en,2*i+1,l,mid);
      int right=query(st,en,2*i+2,mid+1,r);
    
    return left^right;
}
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int q;
    cin >> n >> q;
    
    vector<int>arr(n);
    sgt.assign(4*n,0);
    
    
    for(int i=0;i<n;i++) cin >> arr[i];
    
    buildt(0,0,n-1,arr);
    
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        cout << query(a-1,b-1) << endl;
    }
    
    
}