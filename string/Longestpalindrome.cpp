#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> manacher(string &s) {
    int n = s.size();
    vector<int> ans(n, 0);

    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        ans[i] = (i > r) ? 1 : min(r - i+1, ans[l + r - i]);
        while (i - ans[i] >= 0 && i + ans[i] < n && s[i - ans[i]] == s[i + ans[i]]) ans[i]++;
        if (i + ans[i]-1 > r) {
            l = i - ans[i]+1;
            r = i + ans[i]-1;
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;
    
    string s1="#";
    for(int i=0;i<s.size();i++){
        s1+=s[i];
        s1+='#';
    }

    vector<int>ans=manacher(s1);

    int maxlen=0,centeridx=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]>maxlen){
            maxlen=ans[i];
            centeridx=i;
        }
    }
   
    string pal="";
    int st=centeridx-maxlen+1;
    int end=centeridx+maxlen-1;
    
    for(int i=st;i<=end;i++){
        if(s1[i]!='#') pal+=s1[i];
    }
   
    cout << pal << endl;

}