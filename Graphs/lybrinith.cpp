#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<char>>prev(n,vector<char>(m));
    
    vector<char>direction={'D','R','L','U'};
    
    vector<int>dx={1,0,0,-1};
    vector<int>dy={0,1,-1,0};
    
    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin >> grid[i];
    }
    
    pair<int,int>st;
    pair<int,int>en;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
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
    vis[st.first][st.second]=true;
    
    bool found=false;
    
    while(q.size()>0 && !found){
        auto [x,y]=q.front();
        q.pop();
        
        for(int d=0;d<4;d++){
            int newx=x+dx[d];
            int newy=y+dy[d];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && grid[newx][newy]!='#'){
                
                prev[newx][newy]=direction[d];
                vis[newx][newy]=true;
                q.push({newx,newy});
                
                if(make_pair(newx,newy)==en){
                    found=true;
                    break;
                }
            }
        }
    }
    
 
    if(!found) cout << "NO" << endl;
    else{
        pair<int,int>current={en.first,en.second};
         string ans="";
        while(current!=st){
            char dir=prev[current.first][current.second];
            ans+=dir;
            
            int idx=find(direction.begin(),direction.end(),dir)-direction.begin();
            
            current.first-=dx[idx];
            current.second-=dy[idx];
        }
        
        reverse(ans.begin(),ans.end());
        
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    
    
}