#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<vector<bool>>vis;
int n,m;
vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y,vector<vector<char>>&grid){
     vis[x][y]=true;
     
     for(auto [dx,dy]:dir){
         int newx=dx+x;
         int newy=dy+y;
         
         if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy] && grid[newx][newy]=='.'){
             dfs(newx,newy,grid);
         }
     }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    
    cin >> n >> m;
    vector<vector<char>>grid(n,vector<char>(m));
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
                dfs(i,j,grid);
                room++;
            }
        }
    }
    
    cout << room << endl;
    
}