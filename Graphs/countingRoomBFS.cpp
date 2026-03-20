#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
vector<vector<char>>grid;
vector<vector<bool>>vis;
int n,m;
const vector<pair<int,int>>direction={{1,0},{0,1},{-1,0},{0,-1}};


void bfs(int x,int y){
    
    queue<pair<int,int>>q;
    vis[x][y]=true;
    q.push({x,y});
     
    
    while(q.size()>0){
        auto pair=q.front();
        q.pop();
        
     for(auto [dx,dy]:direction){
    
        
        int newx=dx+pair.first;
        int newy=dy+pair.second;
        
        if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]=='.' && !vis[newx][newy]){
        vis[newx][newy]=true;
            q.push({newx,newy});
        }
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
                bfs(i,j);
                room++;
            }
        }
    }
    
    cout << room << endl;
    
}