#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
int dp[501][125001];
int n;

int twoset(int i, int currSum, int target) {
    if (currSum > target) return 0;
    if (i == n) return currSum == target;

    if (dp[i][currSum] != -1) return dp[i][currSum];

    int putInLeft = twoset(i+1, currSum+i, target) % MOD;
    int putInRight = twoset(i+1, currSum, target) % MOD;

    return dp[i][currSum] = (putInLeft + putInRight) % MOD;
}

signed main() {

    cin >> n;

    int total = (n * (n + 1)) / 2;
    if (total % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= total / 2; ++j)
            dp[i][j] = -1;

    int ans = twoset(1, 0, total / 2);
    cout << ans << endl;
}
