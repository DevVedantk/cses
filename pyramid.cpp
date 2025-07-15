#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

void print( int spaces, int stars){
    if(spaces<0) return;
      for(int j=0;j<spaces;j++) cout << " ";
        for(int j=0;j<stars;j++) cout << "*";
        cout << endl;
        print(spaces-1,stars+2);
}

signed main(){
    int n;
    cin >> n;

    print(n-1,1);
}
