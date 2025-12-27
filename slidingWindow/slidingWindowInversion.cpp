#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>fen;

void update(int idx,int x,int n){
    while(idx<=n){
        fen[idx]+=x;
        idx+=(idx&-idx);
    }
}

int sum(int idx){
    int s=0;
    while(idx>0){
        s+=fen[idx];
        idx-=(idx&-idx);
    }
    return s;
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    set<int>st;
    for(int ele:arr) st.insert(ele);
    map<int,int>mp;
    
    int cnt=1;
    for(int ele:st){
        mp[ele]=cnt;
        cnt++;
    }
    
    int maxe=0;
    for(int i=0;i<n;i++){
        arr[i]=mp[arr[i]];
        maxe=max(maxe,arr[i]);
    }
    fen.assign(maxe+1,0);
    
    vector<int>ans;

     cnt=0;
    for(int i=0;i<k;i++){
      cnt+=(sum(maxe)-sum(arr[i]));
      update(arr[i],1,maxe);
    }
    ans.push_back(cnt);
    
int i = 1, j = k;

while (j < n) {
    int x = arr[i - 1]; 
    int y = arr[j];

  
    cnt -= sum(x-1);      
    update(x, -1, maxe);

  
    cnt += (sum(maxe) - sum(y));
    update(y, 1, maxe);

    ans.push_back(cnt);
    i++;
    j++;
}

    
    for(int ele:ans) cout << ele << " ";
    
}