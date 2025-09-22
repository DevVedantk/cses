#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s,p;
    cin >> s >> p;
    vector<int>lps(p.size(),0);
    
    int pref=0,suff=1;
     while(suff<p.size()){
         if(p[suff]==p[pref]){
             lps[suff]=pref+1;
             pref++;suff++;
         } else{
             if(pref==0){
                 lps[suff]=0;
                 suff++;
             } else{
                pref=lps[pref-1];
             }
         }
     }
     int cnt=0;
     
     suff=0,pref=0;
     while(suff<s.size()){
         if(s[suff]==p[pref]){
             pref++;
             suff++;
             
             if(pref==p.size()){
                 cnt++;
                 pref=lps[pref-1];
             }
         } else{
          if(pref==0) suff++;
          else pref=lps[pref-1];
         }
     }
     
     cout << cnt << endl;
     
}