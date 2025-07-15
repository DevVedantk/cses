#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    int left=0,right=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        right+=arr[i];
        left=max(left,arr[i]);
    }
    
    int maxsum=1e18;
    while(left<=right){
        int mid=(left+right)/2;
        
        int sum=0;
        int block=1;
        
        for(int i=0;i<n;i++){
            if((sum+arr[i])>mid){
                block++;
                sum=0;
            }
            sum+=arr[i];
        }
        
        if(block>k) left=mid+1;
        else{
        if(mid<maxsum) maxsum=mid;
        right=mid-1;    
        }
        
    }
    
    cout << maxsum << endl;
    
}