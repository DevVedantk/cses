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
    
   queue<int>q;

   for(int i=1;i<=n;i++) q.push(i);
   
   while(q.size()>0){
     int skip=q.front();
     q.pop();
     q.push(skip);
     cout << q.front() << " ";
     q.pop();
   }
    




}