#include <bits/stdc++.h>
#define int long long
#define endl '\n'

int MOD=1e9+7;
using namespace std;

signed main(){
   int n;
   cin >> n;
    long double numer = (1 + sqrtl(5)) / 2.0;
    

    long double fib = powl(numer, n)/ sqrtl(5);
    cout << (long long)round(fib)%MOD << endl;
}