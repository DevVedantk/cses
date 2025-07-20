#include <bits/stdc++.h>
#define int long long
#define endl '\n'

int ans=INT_MIN;
using namespace std;

void findans(vector<int>price,vector<int>page,int money,int idx,int curr){
    if(idx==price.size()){
         ans=max(ans,curr);
         return;
    }
    
    if(money-price[idx]>=0){
        findans(price,page,money-price[idx],idx+1,curr+page[idx]);
    }
    findans(price,page,money,idx+1,curr);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,x;
    cin >> n >> x;
    vector<int>pri(n);
    vector<int>page(n);

    for(int i=0;i<n;i++) cin >> pri[i];
    for(int i=0;i<n;i++) cin >> page[i];


    findans(pri,page,x,0,0);
    cout << ans << endl;
}