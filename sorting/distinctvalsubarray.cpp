#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int>arr(n);
   
   for(int i=0;i<n;i++) cin >> arr[i];
    
    int ans=0;
   set<int>st;
   int i=0,j=0;
   while(j<n){
    if(st.find(arr[j])==st.end()){
        st.insert(arr[j]);
        j++;
    } else{
        while(i<n && arr[i]!=arr[j]){
        ans+=((j-1)-i+1);
        st.erase(arr[i]);
            i++;
        }
        ans+=((j-1)-i+1);
        i++;
        j++;
    }
   }
   while(i<n){
        ans+=((j-1)-i+1);
            i++;
        }
   
   cout << ans << endl;
     
}