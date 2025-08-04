#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n;
    cin >> n;

    int total=(n*(n+1))/2;

    if(total%2!=0) cout << "NO" << endl;
    else{
   cout << "YES" << endl;
    int target=total/2;
   
    set<int>st;
    int i=n;
     while(i>=1){
        if(target>=i){
            target-=i;
            st.insert(i);
        }
        i--;
     }

     cout << st.size() << endl;
     for(int ele:st) cout << ele << " ";
     cout << endl;
     cout << n-st.size() << endl;
     for(int i=1;i<=n;i++)
     if(st.find(i)==st.end()) cout << i << " ";
     
    }
}