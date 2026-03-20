#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
vector<vector<char>>grid;
vector<vector<bool>>vis;
int n,m;
const vector<pair<int,int>>direction={{1,0},{0,1},{-1,0},{0,-1}};


void dfs(int x,int y){
    
    vis[x][y]=true;
    
    for(auto [dx,dy]:direction){
        int newx=dx+x;
        int newy=dy+y;
        
        if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='.' && !vis[newx][newy]){
            dfs(newx,newy);
        }
    }
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
   
    cin >> n >> m;
    grid.resize(n,vector<char>(m)); 
    vis.assign(n,vector<bool>(m,false)); 
      
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cin >> grid[i][j];
         }
    }
    
    int room=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
                dfs(i,j);
                room++;
            }
        }
    }
    
    cout << room << endl;
    
}