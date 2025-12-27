#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;

int len;

bool comp(const tuple<int,int,int>& a,
          const tuple<int,int,int>& b) {

    int l1 = get<0>(a);
    int r1 = get<1>(a);
    int l2 = get<0>(b);
    int r2 = get<1>(b);

    if (l1 / len != l2 / len)
        return (l1 / len) < (l2 / len);
    return r1 < r2;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int q;
    cin >> q;
     len=ceil(sqrt(n));
    
    vector<tuple<int,int,int>>que;
    
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        l--;r--;
        que.push_back({l,r,i});
    }
    
    sort(que.begin(),que.end(),comp);
    
    unordered_map<int,int>mp;
    
    int l=get<0>(que[0]),r=get<1>(que[0]);
    vector<int>ans(q);
    for(int i=l;i<=r;i++){
        mp[arr[i]]++;
    }
    int idx=get<2>(que[0]);
    ans[idx]=mp.size();
    
    for(int i=1;i<que.size();i++){
        // l=get<0>(que[i]),r=get<1>(que[i]);
         while(r<get<1>(que[i])){
            r++;
            mp[arr[r]]++;
        }
        
      while(r>get<1>(que[i])){
             if(mp[arr[r]]==1) mp.erase(arr[r]);
            else mp[arr[r]]--;
            r--;
        }
        
        
        while(l<get<0>(que[i])){
            if(mp[arr[l]]==1) mp.erase(arr[l]);
            else mp[arr[l]]--;
            l++;
        }
     
        while(l>get<0>(que[i])){
            l--;
            mp[arr[l]]++;
        }
        
          idx=get<2>(que[i]);
         ans[idx]=mp.size();
    }
    
    for(int ele:ans) cout << ele << endl;
    
}