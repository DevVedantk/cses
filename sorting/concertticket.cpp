#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
    int n,m;
    cin >> n >> m;
   multiset<int>tickets;
  
    for(int i=0;i<n;i++){
       int ele;
       cin >> ele;
       tickets.insert(ele); 
    }
    for(int i=0;i<m;i++){
        int price;
        cin >> price;

        auto it=tickets.upper_bound(price);
        if(it==tickets.begin()){
            cout << -1 << endl;
        } else{
            cout << *(--it) << endl;
            tickets.erase(it);
        }

    }
    
}