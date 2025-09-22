#include <bits/stdc++.h>
#define int long long
#define endl '\n'

int modpow(long long a,long long b,long long MOD){
    long long res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

using namespace std;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s,pat;
    cin >> s >> pat;
    int n=pat.size();
    
    vector<int>power1(n);
    vector<int>power2(n);
    power1[0]=1;
    power2[0]=1;
    int hash1=0,hash2=0;
    
    int M1=1e18+7;
    int M2=1e18+9;
    int p=31ll;
    
       auto make_key=[](long long a,long long b) -> uint64_t{
      return ((uint64_t)a<<32) ^ (uint64_t)b;  
    };
    
     
    for(int i=1;i<n;i++){
        power1[i]=(power1[i-1]*p)%M1;
        power2[i]=(power2[i-1]*p)%M2;
    }
    
      for(int i=0;i<pat.size();i++){
        hash1=(hash1+(pat[i]-'a'+1)*power1[i])%M1;
        hash2=(hash2+(pat[i]-'a'+1)*power2[i])%M2;
    } 
      uint64_t target=make_key(hash1,hash2);
    
     hash1=0,hash2=0;
    
    for(int i=0;i<pat.size();i++){
        hash1=(hash1+(s[i]-'a'+1)*power1[i])%M1;
        hash2=(hash2+(s[i]-'a'+1)*power2[i])%M2;
    }
    
 
    
    int invP1=modpow(p,M1-2,M1);
    int invP2=modpow(p,M2-2,M2);
    
    int cnt=0;
    uint64_t fkey=make_key(hash1,hash2);
    if(fkey==target) cnt++;
    
    int i=1,j=pat.size();
    while(j<(long long)s.size()){
       int out=s[i-1]-'a'+1;
       int in=s[j]-'a'+1;
       
       hash1=(hash1-out+M1)%M1;
       hash1=(hash1*invP1)%M1;
       hash1=(hash1+in*power1[pat.size()-1])%M1;
       
       hash2=(hash2-out+M2)%M2;
       hash2=(hash2*invP2)%M2;
       hash2=(hash2+in*power2[pat.size()-1])%M2;
       
       uint64_t key=make_key(hash1,hash2);
       
     if (key == target) cnt++;

       i++;
       j++;
    }
    
    if(pat.size()>s.size()) cout << 0 << endl;
  else  cout << cnt << endl;
    
   
}