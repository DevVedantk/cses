#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;


signed main(){
 ios::sync_with_stdio(false); cin.tie(NULL);
   
 int n;
 cin >> n;

 vector<int>arr(n);
 for(int i=0;i<n;i++) cin >> arr[i];

 stack<pair<int,int>>st;
  
 cout << 0 << " ";
 st.push({arr[0],1});

  int i=1;
  while(i<n){
    while(st.size()>0 && st.top().first>=arr[i]) st.pop();
    if(st.size()==0) cout << 0 << " ";
    else cout << st.top().second << " "; 
    st.push({arr[i],i+1});
    i++;
  }
 
}