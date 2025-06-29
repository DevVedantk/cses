#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
      int n;
      cin >> n;
      
   vector<pair<int,int>>movie;

    int a,b;
    for(int i=0;i<n;i++){
     cin >> a >> b;
     movie.push_back({b,a});
    }


  sort(movie.begin(),movie.end());
  int watch=0;
  int currendtime=0;

  for(auto [end,start]:movie){
     if(start>=currendtime){
        watch++;
        currendtime=end;
     }
  }
  cout << watch << endl;
      
}