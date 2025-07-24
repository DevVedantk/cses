#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int paths = 0;

void countPaths(string& s, int row, int col, int endr, int endc, int idx, vector<vector<bool>>& visited) {
    if (row < 0 || row > endr || col < 0 || col > endc || visited[row][col]) return;
    if (idx == s.size()) {
        if (row == endr && col == endc) paths++;
        return;
    }

    visited[row][col] = true;

    if (s[idx] == 'L') countPaths(s, row - 1, col, endr, endc, idx + 1, visited);
    else if (s[idx] == 'R') countPaths(s, row + 1, col, endr, endc, idx + 1, visited);
    else if (s[idx] == 'D') countPaths(s, row, col + 1, endr, endc, idx + 1, visited);
    else if (s[idx] == 'U') countPaths(s, row, col - 1, endr, endc, idx + 1, visited);
    else {
        countPaths(s, row - 1, col, endr, endc, idx + 1, visited);
        countPaths(s, row + 1, col, endr, endc, idx + 1, visited);
        countPaths(s, row, col + 1, endr, endc, idx + 1, visited);
        countPaths(s, row, col - 1, endr, endc, idx + 1, visited);
    }

    visited[row][col] = false;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;

    vector<vector<bool>> visited(7, vector<bool>(7, false));
    countPaths(s, 0, 0, 6, 6, 0, visited);

    cout << paths << endl;
}
