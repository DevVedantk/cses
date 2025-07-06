#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n;
    cin >> n;
    
    int ele;
    set<int>st;
    for(int i=0;i<n;i++){
        cin >> ele;
        if(st.size()==0) st.insert(ele);
        else{
            auto it=st.upper_bound(ele);
            if(it==st.end()) st.insert(ele);
            else{
                st.erase(it);
                st.insert(ele);
            }
        }
    }

    cout << st.size() << endl;
    
}