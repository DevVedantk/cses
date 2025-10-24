#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> zalgo(string& s){
    vector<int>z(s.size());
    int n=s.size();
    int l=0,r=0;
    for(int i=1;i<s.size();i++){
        if(i<r) z[i]=min(r-i,z[i-l]);
        
        while(z[i]+i<n && s[z[i]]==s[z[i]+i]) z[i]++;
        if(z[i]+i>r){
            r=z[i]+i;
            l=i;
        }
    }
    return z;
}
vector<int> kmp(string& s){
    int n=s.size();
    vector<int>lps(n);
    
    int pref=0,suff=1;
    while(suff<n){
        if(s[pref]==s[suff]){
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
   vector<int>z=zalgo(s);
   
   for(int ele:z) cout << ele << " ";
   cout << endl;
   for(int ele:lps) cout << ele << " ";
   

}