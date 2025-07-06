#include <bits/stdc++.h>
#define int long long
#define endl '\n'
 
using namespace std;
 
 
void PerfromOperation(multiset<int,greater<int>>& st,map<int,int,greater<int>>& mp,map<int, int, greater<int>>::iterator pair,int ele){
    
           int left=pair->first;
            int right=pair->second;
            
            auto it = st.find(right-left);
           if (it != st.end()) {
             st.erase(it);
               }
            
         st.insert(ele-left); 
         st.insert(right-ele); 
          mp.erase(left);
          mp.insert({left,ele});
          mp.insert({ele,right});
}
 
signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,n;
    cin >> x >> n;
 
    multiset<int,greater<int>>st;
    map<int,int,greater<int>>mp;
 
    int ele;
    for(int i=0;i<n;i++){
       cin >> ele;
       
       if(mp.size()==0){
         mp.insert({0,ele});
         mp.insert({ele,x});
         st.insert(ele-0);
         st.insert(x-ele);
       } else{
         auto it=mp.upper_bound(ele);
        //  cout << it->first << " " << it->second << endl;
         if(it->first<ele && it->second>ele){
            PerfromOperation(st,mp,it,ele);
           
         } else{
             it--;
              PerfromOperation(st,mp,it,ele);
         }
       }
       
     cout << *st.begin() << " ";
    }
 
    
}