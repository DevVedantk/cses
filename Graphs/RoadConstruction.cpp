#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


int find(int x,vector<int>&par){
    if(x==par[x]) return x;
    return par[x]=find(par[x],par);
}
set<int>st;
priority_queue<int>pq;
vector<int>sizes;

void unions(int x,int y,vector<int>&par,vector<int>&rank){
    int x_par=find(x,par);
    int y_par=find(y,par);
    
    if(x_par==y_par) return;
  
    
      if(st.find(x_par)!=st.end()) st.erase(x_par);
        if(st.find(y_par)!=st.end()) st.erase(y_par);
        
    if(rank[x_par]<rank[y_par]){
        par[x_par]=y_par;
     
        st.insert(y_par);
          sizes[y_par]+=sizes[x_par];
        pq.push(sizes[y_par]);
    } else if(rank[x_par]>rank[y_par]){
        par[y_par]=x_par;
          st.insert(x_par);
          sizes[x_par]+=sizes[y_par];
        pq.push(sizes[x_par]);
    } else{
        par[x_par]=y_par;
        rank[y_par]++;
        st.insert(y_par);
        sizes[y_par]+=sizes[x_par];
        pq.push(sizes[y_par]);
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int>par(n+1,0);
    vector<int>rank(n+1,1);
    sizes.assign(n+1,1);
    for(int i=1;i<=n;i++) st.insert(i);

for(int i=1;i<=n;i++) par[i]=i;

    for(int i=0;i<m;i++){
        int a,b;
       cin >> a >> b;
       if(find(a,par)!=find(b,par)){
           unions(a,b,par,rank);
       }    
       cout << st.size() << " " << pq.top() << endl;
    
    }
    
}