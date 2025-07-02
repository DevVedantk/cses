#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;
const int INF=1e18;
const int MOD=1e9+7;

int findpow(int a,int b){
    if(b==0) return 1;
    int half=findpow(a,b/2);
    if(b%2==0) return half*half;
    else return a*half*half; 
}

int findceil(int a,int b){
    return (a+b-1)/b;
}


signed main(){
    int n;
    cin >> n;
    vector<int>arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    set<int>st;

  int i=0,j=0;
  int maxlen=INT_MIN;

  while(j<n){
   if(j<n && st.find(arr[j])==st.end()){
     st.insert(arr[j]);
     j++; 
   } else{
     while(arr[i]!=arr[j]){
       st.erase(arr[i]);
       i++; 
     }
     i++;
     j++;
   }   
     int size=st.size();
    maxlen=max(maxlen,size);
  }

  cout << maxlen << endl;

}