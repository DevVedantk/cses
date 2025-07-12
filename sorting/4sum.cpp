#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;

signed main(){
    //  ios::sync_with_stdio(false); cin.tie(NULL);
     
     int n,target;
     cin >> n >> target;

     vector<int>arr(n);
     multimap<int,int>mp;
     for(int i=0;i<n;i++){
        cin >> arr[i];
        mp.insert({arr[i],i});
     }
    
     sort(arr.begin(),arr.end());
     
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int a=i+1;a<n;a++){
        int j=a+1,k=n-1;

        while(j<k){
            if((arr[i]+arr[a]+arr[j]+arr[k])==target){
                flag=true;
                auto it=mp.find(arr[i]);
                cout << it->second+1 << " ";
                mp.erase(it);
              
                it=mp.find(arr[a]);
                cout << it->second+1 << " ";
                mp.erase(it);
              
                it=mp.find(arr[j]);
                cout << it->second+1 << " ";
                mp.erase(it);
                
                it=mp.find(arr[k]);
                cout << it->second+1 << " ";
                mp.erase(it);
                break;
            } else if((arr[i]+arr[a]+arr[j]+arr[k])>target) k--;
             else j++;
        }
        if(flag) break;
    }
     if(flag) break;
    }
    
    if(!flag) cout << "IMPOSSIBLE" << endl;
    

}