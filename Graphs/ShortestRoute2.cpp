#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m,q;
    cin >> n >> m >> q;
    
    vector<vector<int>>dist(n,vector<int>(n,LLONG_MAX));
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        u--;v--;
        dist[u][v]=min(wt,dist[u][v]);
        dist[v][u]=min(wt,dist[v][u]);
    }
    
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    
    //run floyd warshall
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        long long ans=dist[a][b];
        if(ans==LLONG_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }
    
    
    
    
}