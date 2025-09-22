#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


void solve(string& s,vector<bool>& vis,string perm,vector<string>& ans,set<string>& st){
    if(perm.size()==s.size()){
    if(st.find(perm)==st.end())    ans.push_back(perm);
    st.insert(perm);
        return;
    }
    
    for(int i=0;i<s.size();i++){
        if(vis[i]==false){
            vis[i]=true;
            solve(s,vis,perm+s[i],ans,st);
            vis[i]=false;
        }
    }
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<string>ans;
    string s;
    cin >> s;
    int n=s.size();
    
    set<string>st;
    vector<bool>vis(n,false);
    string perm="";
    solve(s,vis,perm,ans,st);
    
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
}