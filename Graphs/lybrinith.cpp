#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    
    cin >> n >> m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    
    vector<vector<char>>prev(n,vector<char>(m));
    vector<char>direction={'L','R','U','D'};
    vector<int>dx={0,0,-1,1};
    vector<int>dy={-1,1,0,0};
    
    pair<int,int>st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='A'){
                st.first=i;
                st.second=j;
            }
            if(grid[i][j]=='B'){
                en.first=i;
                en.second=j;
            }
        }
    }
    
    queue<pair<int,int>>q;
    q.push({st.first,st.second});
    bool found=false;
    
    while(q.size()>0 && !found){
        auto [x,y]=q.front();
        q.pop();
        
        for(int d=0;d<4;d++){
            int newx=x+dx[d];
            int newy=y+dy[d];
            
            if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy] && grid[newx][newy]!='#'){
                vis[newx][newy]=true;
                q.push({newx,newy});
                prev[newx][newy]=direction[d];
                
                if(make_pair(newx,newy)==en){
                    found=true;
                    break;
                }
            }
        }
        
    }
    
    if(!found) cout << "NO" << endl;
    else{
        string ans="";
        pair<int,int>curr=en;
        
        while(curr!=st){
            char dir=prev[curr.first][curr.second];
            ans+=dir;
            
            int idx=find(direction.begin(),direction.end(),dir)-direction.begin();
            
            curr.first-=dx[idx];
            curr.second-=dy[idx];
        }
        
        cout << "YES" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
        
        
        
    }   
}