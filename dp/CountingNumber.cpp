#include <bits/stdc++.h>
#define int long long
#define endl '\n'
 
using namespace std;
 
int dp[20][2][2][12];
int solve(string& R,int n,int tight,int leading_zeros,int prevTaken){
    
    //leading_zero=0 means it don't contain leading 0 like 000001 etc
    if(n==0){
       return 1;
    }
   if(dp[n][tight][leading_zeros][prevTaken]!=-1) return  dp[n][tight][leading_zeros][prevTaken];
   
    int ans=0;
    int upperB=tight? (R[R.size()-n]-'0') :9;
 
    for(int deg=0;deg<=upperB;deg++){
       int newleading=(leading_zeros&(deg==0));
 
       if(newleading){
          ans+=solve(R,n-1,tight&(upperB==deg),1,10);
       } else{
           if(prevTaken!=deg){
              ans+=solve(R,n-1,tight&(upperB==deg),0,deg);  
           }
       }
    }
    return dp[n][tight][leading_zeros][prevTaken]=ans;
}
 
signed main(){
   ios::sync_with_stdio(false); cin.tie(NULL);
   
   int a,b;
   cin >> a >> b;
    
 
   string R=to_string(b);
   string L=to_string(a-1);
   
   //0 to R
     memset(dp,-1,sizeof(dp));
   int ans1=solve(R,R.size(),1,1,0);
     memset(dp,-1,sizeof(dp));
   int ans2=solve(L,L.size(),1,1,0);
   
   cout << ans1-ans2 << endl;
}
