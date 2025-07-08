#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main(){
   ios::sync_with_stdio(false); cin.tie(NULL);
   
   int n;
   cin >> n;
   vector<vector<int>>arr(n,vector<int>(3));
   
   int left,right;
   for(int i=0;i<n;i++){
      cin >> arr[i][0];
      cin >> arr[i][1];
       arr[i][2]=i;
   }
   sort(arr.begin(),arr.end());
   
  priority_queue<pair<int,int>,vector<pair<int,int>>,
  greater<pair<int,int>>>pq;
  
  vector<int>rooms(n);
   
   int i=0;
   int maxroom=0;
   
  while(i<n){
      int comeTime=arr[i][0];
      int leaveTime=arr[i][1];
      int idx=arr[i][2];
      
      if(pq.size()<1 || pq.top().first>=comeTime){
          maxroom++;
          rooms[idx]=maxroom;
          pq.push({leaveTime,maxroom});
      } else{
         auto pair=pq.top();
         pq.pop();
         rooms[idx]=pair.second;
         pq.push({leaveTime,pair.second});
      }
      i++;
  }
   
   cout << maxroom << endl;
   for(int ele:rooms) cout << ele << " ";
  
  
   
}