#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int memo[1000001];

int MOD=1e9+7;

int powerfn(int a,int b){
   
   if(b==0) return 1;
   
   if(memo[b]!=-1) return memo[b]%MOD;
   int half=powerfn(a,b/2);
   if(b%2==0) return memo[b]=((half%MOD)*(half%MOD))%MOD;
   return memo[b]=((a%MOD)*(half%MOD)*(half%MOD))%MOD;
}

signed main(){
int n;
cin >> n;
   memset(memo,-1,sizeof(memo));
   int ans=powerfn(2,n);
   cout << ans << endl;
   
}