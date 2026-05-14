#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int up[200001][30];
int vis[200001];

int ans_query(int node,int jump){

    if(jump==0) return node;

    for(int i=29;i>=0;i--){
        if(jump >= (1LL<<i)){
            return ans_query(up[node][i],jump-(1LL<<i));
        }
    }

    return node;
}

void binary_lifting(vector<int>&par){
    int n=par.size();
      for(int i=0;i<n;i++){
          up[i][0]=par[i];
      }
      
      for(int j=1;j<30;j++){
          for(int i=0;i<n;i++){
              up[i][j]=up[up[i][j-1]][j-1];
          }
      }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,q;
    cin >> n >> q;
   
    
    vector<int>par(n+1,0);
    for(int i=1;i<=n;i++) cin >> par[i];

binary_lifting(par);

    for(int i=0;i<q;i++){
        int node,k;
        cin >> node >> k;
        cout << ans_query(node,k) << endl;
    }
}