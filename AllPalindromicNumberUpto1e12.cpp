#include <bits/stdc++.h>
#define int long long
#define endl '\n'


using namespace std;

// number of operation is upto 1e6  for 1e12
// time complexity is 12*1e6  upto  1e12 because we are reversing other half and to reach 1e12 at max we will go upto 1e6

signed main(){
      vector<int>palindromes;
    
    for(int i=1;i<=12;i++){
       int halflen=(i+1)/2;
       
       int start=pow(10,halflen-1);
       int end=pow(10,halflen);
       
       for(int num=start;num<end;num++){
        string full;
        string half=to_string(num);
        string rev=half;
         reverse(rev.begin(),rev.end());
         if(i%2==0){
            full=half+rev;
            int palindrome=stoll(full);
            palindromes.push_back(palindrome);
         }
          else{
            full=half+rev.substr(1,rev.size());
              int palindrome=stoll(full);
            palindromes.push_back(palindrome);
          }
       }
    }
    
    for(int ele:palindromes) cout << ele << " ";
    cout << endl;
    
}