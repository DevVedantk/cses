#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;


signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

   
    for(int i=1;i<=n;i++){
        cout <<  ((i-1)*(i+4)*((i*i)-(3*i)+4))/2 << endl;
    }
}