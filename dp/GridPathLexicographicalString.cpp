#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            arr[i][j] = row[j];
        }
    }

    vector<vector<string>> dp(n, vector<string>(n, "~"));
    dp[n-1][n-1] = string(1, arr[n-1][n-1]);

    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(i == n-1 && j == n-1) continue; // skip base case
            if(i+1 < n)
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[i+1][j]);
            if(j+1 < n)
                dp[i][j] = min(dp[i][j], arr[i][j] + dp[i][j+1]);
        }
    }

    cout << dp[0][0] << endl;
}
