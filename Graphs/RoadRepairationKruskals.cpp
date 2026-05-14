#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;



 int find(int node,vector<int>&par){
        if(node==par[node]) return node;
        
        return par[node]=find(par[node],par);
    }
    
    void unions(int a,int b,vector<int>&par,vector<int>&rank){
        int par_a=find(a,par);
        int par_b=find(b,par);
        
        if(par_a==par_b) return;
        
        if(rank[par_a]>rank[par_b]){
            par[par_b]=par_a;
        } else if(rank[par_a]<rank[par_b]){
            par[par_a]=par_b;
        } else{
            par[par_a]=par_b;
            rank[par_b]++;
        }
    }


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
     vector<vector<int>>edges(m,vector<int>(3));
     vector<int>par(n+1,0);
     vector<int>rank(n+1,0);
     for(int i=1;i<=n;i++) par[i]=i;
     
  
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin >> a >>b >> wt;
        edges[i][0]=a;
        edges[i][1]=b;
        edges[i][2]=wt;
    }
    

sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2]; 
         });
         
         int t=0;
         for(int i=0;i<edges.size();i++){
             int a=edges[i][0],b=edges[i][1],wt=edges[i][2];
             if(find(a,par)!=find(b,par)){
                 unions(a,b,par,rank);
                 t+=wt;
             }
         }
         int c=0;
         for(int i=1;i<=n;i++){
             if(find(i,par)==i) c++;
         }
         
         if(c>1) cout << "IMPOSSIBLE" << endl; 
         else cout << t << endl;

}