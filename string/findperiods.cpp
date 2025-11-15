#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> zalgo(string& s){
    vector<int>z(s.size());
    int n=s.size();
    int l=0,r=0;
    
    for(int i=1;i<n;i++){
       if(i<r) z[i]=min(r-i,z[i-l]);
       
       while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
       
       if(i+z[i]>r){
           l=i;
           r=i+z[i];
       }
    }
    return z;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    
    int n=s.size();
    vector<int>z=zalgo(s);

   for(int i=0;i<n;i++){
       
       if((z[i]+i)>=n) cout << i << " ";
   }
   cout << n  << endl;
    
    
}