#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


bool check(int row,int col,vector<int>& queens){
    for(int i=0;i<row;i++){
        int prevRow=i;
        int prevCol=queens[i];

        if(prevCol==col || abs(prevCol-col)==abs(prevRow-row))
        return 0;
    }
    return 1;
}
int rec(int level,int n,vector<int>& queens,vector<vector<char>>& arr){
    if(level>n) return 0;

    if(level==n) return 1;

    int ans=0;
    for(int col=0;col<n;col++){
        if(arr[level][col]=='*') continue;
        if(check(level,col,queens)){
           queens[level]=col;
           ans+=rec(level+1,n,queens,arr);
           queens[level]=-1;
        }
    }
    return ans;
}

signed main(){
    
     vector<vector<char>>arr(8,vector<char>(8));
     for(int i=0;i<8;i++){
        for(int j=0;j<8;j++) cin >> arr[i][j];
     }
     vector<int>queens(8,-1);

     cout << rec(0,8,queens,arr) << endl;
}