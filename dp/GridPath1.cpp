#include <bits/stdc++.h>
#define int long long
#define endl '\n'
 
const int MOD=1e9+7;
using namespace std;
 
int findway(int n,int row,int col,vector<vector<char>>& grid,vector<vector<int>>& memo){
    if(row==n || col==n || grid[row][col]=='*') return 0;
    if(row==n-1 && col==n-1) return 1;
     if(memo[row][col]!=-1) return memo[row][col];
 
    return memo[row][col]=(findway(n,row,col+1,grid,memo)%MOD+findway(n,row+1,col,grid,memo)%MOD)%MOD;
}
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<char>>grid(n,vector<char>(n));
    vector<vector<int>>memo(n,vector<int>(n,-1));
    
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
   
   int ways=findway(n,0,0,grid,memo);
   cout << ways << endl;
}
 
