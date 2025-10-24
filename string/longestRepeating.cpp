#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

string check(int len,string& s){
    int MOD=1e9+7;
    int p1=31,p2=37;
    
    vector<long long>power1(len);
    vector<long long>power2(len);
    
    power1[len-1]=1;
    power2[len-1]=1;
    for(int i=len-2;i>=0;i--){
        power1[i]=(power1[i+1]*p1)%MOD;
        power2[i]=(power2[i+1]*p2)%MOD;
    }

    long long h1=0,h2=0;
    for(int i=len-1;i>=0;i--){
        h1=(h1+(s[i]-'a'+1)*power1[i])%MOD;
        h2=(h2+(s[i]-'a'+1)*power2[i])%MOD;
    }

    set<pair<long long,long long>>seen;
    seen.insert({h1,h2});

    int i=1,j=len;
    while(j<s.size()){
      h1=(h1-(s[i-1]-'a'+1)*power1[0])%MOD;
      h2=(h2-(s[i-1]-'a'+1)*power2[0])%MOD;
      
      if(h1<0) h1+=MOD;
      if(h2<0) h2+=MOD;
      
      h1=(h1*p1+(s[j]-'a'+1))%MOD;
      h2=(h2*p2+(s[j]-'a'+1))%MOD;
       
       if(seen.find({h1,h2})!=seen.end()) return s.substr(i,len);
        
        seen.insert({h1,h2});
      i++;j++;
    }

    return  "";

}

signed main(){
ios::sync_with_stdio(false); cin.tie(NULL);

string s;
cin >> s;
        int l=1,h=s.size();

        string ans="";
        while(l<=h){
            int mid=(l+h)/2;
            
        string longest=check(mid,s);
        if(longest!=""){
            ans=longest;
            l=mid+1;
        } else h=mid-1;
        }
      
        if(ans=="") cout << -1 << endl;
       else cout << ans << endl;


}