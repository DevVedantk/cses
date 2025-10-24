#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<string> gray(int n){
    if(n==1) return {"0","1"};

    vector<string>prevcode=gray(n-1);

    vector<string>prevRev=prevcode;
    reverse(prevRev.begin(),prevRev.end());

    int i=0,size=prevcode.size();

    while(i<size){
      string appendzero="0"+prevcode[i];

      prevcode[i]="1"+prevRev[i];
      prevcode.push_back(appendzero);
      i++;
    } 

    return prevcode;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<string>ans=gray(n);

    for(int i=0;i<ans.size();i++) cout << ans[i] << endl;

}