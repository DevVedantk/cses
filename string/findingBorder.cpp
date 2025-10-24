#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> kmp(string& s){
    int n=s.size();
    vector<int>lps(n);
    
    int pref=0,suff=1;
    while(suff<n){
      if(s[suff]==s[pref]){
          lps[suff]=pref+1;
          pref++;suff++;
      } else{
          if(pref==0){
              lps[suff]=0;
              suff++;
          } else pref=lps[pref-1];
      }
    }
     return lps;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
     
     string s;
     cin >> s;
     
     vector<int>lps=kmp(s);
     vector<int>ans;
     
     int j=lps.size()-1;
    //  for(int ele:lps) cout << ele << " ";
    //  cout << endl;
    
    //  cout << "start " << j << endl;
     while(j>0){
        if(lps[j]>0) ans.push_back(lps[j]);
        //  cout << j << " " << lps[j] << endl;
         j=lps[j]-1;
     }
     
     sort(ans.begin(),ans.end());
     for(int ele:ans) cout << ele << " ";
     
}