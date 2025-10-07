#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
 
using namespace std;
 
signed main(){
    
    int t;
    cin >> t;
 
    while(t-- >0){
      
        int a,b;
 
        cin >> a >>b;
 
        if(a==0 && b==0) cout <<"YES" <<endl;
       else if((a+b)%3==0 && min(a,b)>=(max(a,b)/2)) cout <<"YES" <<endl;
        else cout << "NO" <<endl;
 
    }
}
