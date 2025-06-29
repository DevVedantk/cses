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

    int maxsum=INT_MIN;
     
    int sum=0;
    int last=0;
    int start=-1;
    int st;
    for(int i=0;i<n;i++){
        sum+= arr[i];
        if(start==-1) start=i;
        if(sum>maxsum){
            st=start;
            last=i;
            maxsum=sum;
        }
        if(sum<0){
            start=-1;
             sum=0;
        }
    }
    
    // cout << "idx "  << last << end; 
    //st is start point and last is ending point
    sum=0;
    for(int i=st;i<=last;i++) sum+=arr[i];
    
    cout << "check sum is " << sum << endl;
    cout << maxsum << endl;



    }  
