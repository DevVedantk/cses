#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

bool check(int r,int c,vector<vector<char>>& pat,vector<vector<char>>& arr){
    // bool f=true;
    
  
    int col=c;
    for(int i=0;i<pat.size();i++){
        for(int j=0;j<pat[i].size();j++){
            if(pat[i][j]!=arr[r][col]) return false;
            col++;    
        }
        r++;
        col=c;
    }
    return true;
    
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n1,n2;
    cin >> n1 >> n2;
    vector<vector<char>>pat(n1,vector<char>(n2));
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++) cin >> pat[i][j];
    }
    
    int m1,m2;
    cin >> m1 >> m2;
    vector<vector<char>>arr(m1,vector<char>(m2));
    for(int i=0;i<m1;i++){
        for(int j=0;j<m1;j++) cin >> arr[i][j];
    }
    
    
    vector<pair<int,int>>ans;
   
   for(int i=0;i<m1;i++){
       for(int j=0;j<m2;j++){
          if(check(i,j,pat,arr)){
              ans.push_back({i+1,j+1});
          }
       }
   }
   
   cout << "size " << ans.size() << endl;
   
   for(auto ele:ans) cout << ele.first << " " << ele.second << endl;
   
    
}





