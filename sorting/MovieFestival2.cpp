#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
    
bool mysort(const pair<int,int>& a,const pair<int,int>& b){
    return a.first<b.first;   
   
}

signed main(){
    int n,k;
    cin >> n >> k;
    
    vector<pair<int,int>>arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        cin >> arr[i].second; 
    }

    sort(arr.begin(),arr.end(),mysort);
     int watch=0;
     
     multiset<int>st;
     for(int i=0;i<k;i++){
         st.insert(arr[i].second);
     }
     
     for(int i=k;i<n;i++){
         auto mn=st.begin();  
         auto mx=st.rbegin();
         
         if(arr[i].first>=(*mn)){
             watch++;
             st.erase(st.find(*mn));
             st.insert(arr[i].second);
         } else if(arr[i].second<(*mx)){
             st.erase(st.find(*mx));
             st.insert(arr[i].second);
         }
     }
    
    cout << watch+st.size() <<endl;
     
  
}