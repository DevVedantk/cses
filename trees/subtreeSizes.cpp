#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
vector<int>ans;

int dfs(int node,vector<vector<int>>& adj){
    int cnt=1;
    
    for(int child:adj[node]){
        cnt+=dfs(child,adj);
    }
    ans[node]=cnt-1;
    
    return cnt;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
  vector<vector<int>> adj(n+1);
    
    for(int i=1;i<=n-1;i++){
        int ele;
        cin >> ele;
        adj[ele].push_back(i+1);
    }
    ans.assign(n+1,0);
  int size= dfs(1,adj);
  
    // cout << size << endl;
  
  for(int i=1;i<=n;i++) cout << ans[i] << " ";  
}


