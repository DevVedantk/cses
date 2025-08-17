#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int m,d;
int MOD=1e9+7;
int dp[3001][2][2][3001][2];

string subone(string s){
   int i=s.size()-1;

   while(i>=0){
    if(s[i]>'0'){
        s[i]--;
        break;
    } else{
        s[i]='9';
        i--;
    }
   }

  i=0;
   while(i<s.size() && s[i]=='0') i++;
   if(i>=s.size()) return "0";
   return s.substr(i); 

}

int solve(string& R,int n,int tight,int leading_zeros,int num,int even){
    if(n==0){
        return (num==0 && !leading_zeros);
    }
    if(dp[n][tight][leading_zeros][num][even]!=-1) dp[n][tight][leading_zeros][num][even];
    
    int ans=0;
    int upperB = tight ? (R[R.size()-n]-'0') : 9;
    
    if(even){
        if(leading_zeros){
            // still skipping, can only place 0
            if(0 <= upperB)
                ans = (ans + solve(R, n-1, tight&(upperB==0), 1, 0, 0)) % MOD;
        } else {
            // enforce: even pos must be d
            if(d <= upperB)
                ans = (ans + solve(R, n-1, tight&(upperB==d), 0, (num*10+d)%m, 0)) % MOD;
        }
    } else {
        for(int deg=0; deg<=upperB; deg++){
            int newleading = leading_zeros & (deg==0);
            if(newleading){
                ans = (ans + solve(R, n-1, tight&(deg==upperB), 1, 0, 0)) % MOD;
            } else if(deg != d){
                ans = (ans + solve(R, n-1, tight&(deg==upperB), 0, (num*10+deg)%m, 1)) % MOD;
            }
        }
    }
    return dp[n][tight][leading_zeros][num][even] = ans;
}

signed main(){
       
       cin >> m >> d;
       string L,R;
       cin >> L >> R;
      
       L=subone(L);
    
        memset(dp,-1,sizeof(dp));
      int ans1=solve(R,R.size(),1,1,0,0); 
       memset(dp,-1,sizeof(dp));
      int ans2=solve(L,L.size(),1,1,0,0); 
      cout << ((ans1-ans2)%MOD+MOD)%MOD << endl;
}