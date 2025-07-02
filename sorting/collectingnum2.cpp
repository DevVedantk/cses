#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n,m;
    cin >> n >> m;

    vector<int>arr(n);
    unordered_map<int,int>mp;
 
    for(int i=0;i<n;i++){
         cin >> arr[i];
         mp[arr[i]]=i;
    }
 
    sort(arr.begin(),arr.end());
    vector<int>indices(n);
    for(int i=0;i<n;i++){
       int idx=mp[arr[i]];
       indices[i]=idx; 
    }
     mp.clear();
     
     for(int i=0;i<n;i++) mp[indices[i]]=i;


      int ans=1;
      for(int i=1;i<n;i++){
        if(indices[i-1]>indices[i]) ans++;
      }
     
     set<pair<int,int>>st;

      for(int i=0;i<m;i++){
        int idx1,idx2;
        cin >> idx1;
        cin >> idx2;
        idx1--; idx2--;
         
        int index1=mp[idx1];
        int index2=mp[idx2];

        if((index1-1)>=0) st.insert({indices[index1-1],indices[index1]});
        if((index1+1)<n) st.insert({indices[index1],indices[index1+1]});

        if((index2-1)>=0) st.insert({indices[index2-1],indices[index2]});
        if((index2+1)<n) st.insert({indices[index2],indices[index2+1]});
         
        for(auto ele:st){
           if(ele.first>ele.second) ans--; 
        }
       
        st.clear();
        swap(indices[index1],indices[index2]);
        mp[idx1]=index2;
        mp[idx2]=index1;


         index1=mp[idx1];
         index2=mp[idx2];

        if((index1-1)>=0) st.insert({indices[index1-1],indices[index1]});
        if((index1+1)<n) st.insert({indices[index1],indices[index1+1]});

        if((index2-1)>=0) st.insert({indices[index2-1],indices[index2]});
        if((index2+1)<n) st.insert({indices[index2],indices[index2+1]});
         
        for(auto ele:st){
           if(ele.first>ele.second) ans++; 
        }
        st.clear();

        cout << ans << endl;

      }


    
}