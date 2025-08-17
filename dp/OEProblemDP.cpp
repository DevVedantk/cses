#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int dp[10][2][2][100][100];

int solve(string& R,int n,int tight,int leading_zeros,int evensum,int oddsum){
    if(n==0){
        return (evensum>oddsum);
    }   
    if(dp[n][tight][leading_zeros][evensum][oddsum]!=-1)
    return dp[n][tight][leading_zeros][evensum][oddsum];
    
    int ans=0;
     int upperB=tight?(R[R.size()-n]-'0'):9;
    
    for(int deg=0;deg<=upperB;deg++){
        int newleading=leading_zeros&(deg==0);
        
       if(newleading){
           ans+=solve(R,n-1,tight&(deg==upperB),1,evensum,oddsum);
       } else{
           if(deg%2==0){
           ans+=solve(R,n-1,tight&(deg==upperB),newleading,evensum+deg,oddsum);
           } else{
        
           ans+=solve(R,n-1,tight&(deg==upperB),newleading,evensum,oddsum+deg);       
           }
           
           }
       }    
    return dp[n][tight][leading_zeros][evensum][oddsum]=ans;
    }     


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t-- >0){
        int a,b;
        cin >> a >> b;

        string L=to_string(a-1);
        string R=to_string(b);

     memset(dp,-1,sizeof(dp));
        int ans1=solve(R,R.size(),1,1,0,0);
     memset(dp,-1,sizeof(dp));
        int ans2=solve(L,L.size(),1,1,0,0);

        cout << ans1-ans2 << endl;
    }

}