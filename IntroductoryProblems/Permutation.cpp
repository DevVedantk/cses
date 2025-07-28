#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    if(n==2 || n==3) cout << "NO SOLUTION";
    else{
        if(n%2==0){
            for(int i=n-1;i>=1;i-=2) cout << i << " ";
            for(int i=n;i>=2;i-=2) cout << i << " ";
        } else{
           for(int i=n;i>=1;i-=2) cout << i << " ";
            for(int i=n-1;i>=2;i-=2) cout << i << " "; 
        }
    }
}