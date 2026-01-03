#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int>start;
vector<int>endt;

int timer=0;
int maxt=0;

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

void euler_tour(int node,int parent,vector<vector<int>>& adj){
    start[node]=++timer;
    maxt=max(maxt,timer);
    
    for(int child:adj[node]){
      if(child==parent) continue;
      euler_tour(child,node,adj);
    }
    endt[node]=timer;
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int>value(n+1);
    for(int i=1;i<=n;i++) cin >> value[i];
    
    vector<vector<int>>adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    start.assign(n+1,0);
    endt.assign(n+1,0);
    
    euler_tour(1,-1,adj);
    
    vector<tuple<int,int,int>>qry;
    
    for(int i=1;i<=n;i++){
         qry.push_back({start[i],endt[i],i});
    }
    
     len=ceil(sqrt(maxt));
    
      sort(qry.begin(),qry.end(),comp);
      
      vector<int>arr(maxt+1);
      
      for(int i=1;i<=n;i++){
          arr[start[i]]=value[i];
      }
      
      //now MO's algorithm on arr;
      unordered_map<int,int>mp;
      int q=qry.size();
     int l=get<0>(qry[0]),r=get<1>(qry[0]);
    vector<int>ans(q+1);
    for(int i=l;i<=r;i++){
        mp[arr[i]]++;
    }
    int idx=get<2>(qry[0]);
    ans[idx]=mp.size();
    
    for(int i=1;i<qry.size();i++){
        // l=get<0>(que[i]),r=get<1>(que[i]);
         while(r<get<1>(qry[i])){
            r++;
            mp[arr[r]]++;
        }
        
      while(r>get<1>(qry[i])){
             if(mp[arr[r]]==1) mp.erase(arr[r]);
            else mp[arr[r]]--;
            r--;
        }
        
        
        while(l<get<0>(qry[i])){
            if(mp[arr[l]]==1) mp.erase(arr[l]);
            else mp[arr[l]]--;
            l++;
        }
     
        while(l>get<0>(qry[i])){
            l--;
            mp[arr[l]]++;
        }
        
          idx=get<2>(qry[i]);
         ans[idx]=mp.size();
    }
    
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    
}