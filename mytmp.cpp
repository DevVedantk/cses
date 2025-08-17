#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int ans=0;
int maxproduct=-1e18;

void solve(string& R,int n,int tight,int leading_zeros,int num,int product){
      if(n==0){
        if(maxproduct<product){
          maxproduct=product;
          ans=num;
        }
        return;
      }

     int upperB=tight?(R[R.size()-n]-'0'):9;

     for(int deg=0;deg<=upperB;deg++){
      int newleading=leading_zeros&(deg==0);

      if(newleading) solve(R,n-1,0,newleading,num*10+deg,product*deg);
      else  solve(R,n-1,tight&(deg==upperB),newleading,num*10+deg,product*deg);
     }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a,b;
    cin >> a >> b;

    string L=to_string(a-1);
    string R=to_string(b);

    solve(R,R.size(),1,1,0,1);
     solve(L,L.size(),1,1,0,1);

     cout << ans << endl;
}