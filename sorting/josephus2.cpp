#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'


signed main(){
    int n,k;
    cin >> n >>k;

    ordered_set<int>st;
    for(int i=1;i<=n;i++) st.insert(i);

     int start=0;
    while(st.size()>0){
    start=start%st.size();
    
    int removed=(start+k)%st.size();
   start=removed;
    auto it=st.find_by_order(removed);

    cout << *it <<" ";
    st.erase(it);

    }
    

}