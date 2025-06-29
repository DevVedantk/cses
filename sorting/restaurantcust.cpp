#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
    
    int n;
    cin >> n;
    vector<int>arrive;
    vector<int>leave;
   
    int arr,leav;
    for(int i=0;i<n;i++){
      cin >> arr;
      arrive.push_back(arr);
      cin >> leav;
      leave.push_back(leav);
    }


    sort(arrive.begin(),arrive.end());
    sort(leave.begin(),leave.end());
    
    int i=0,j=0;
    int customer=0,cnt=0;
     while(i<n){
        if(arrive[i]<=leave[j]){
            cnt++;
            customer=max(customer,cnt);
            i++;
        } else{
            j++;
            cnt--;
        }
     }

     cout << customer << endl;

}