#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 10;
vector<int> v({1, 3, 6, 10, 15});

int calculation(int indx, int sum, vector<int> &dp) {
    if (indx == 5) {
        return (sum == 0) ? 0 : INT_MAX / 2;
    }
    if (dp[sum] != -1) {
        return dp[sum];
    }
    int take = INT_MAX, nontake = 0;
    if (sum >= v[indx]) {
        take = 1 + calculation(indx, sum - v[indx], dp);
    }
    nontake = calculation(indx + 1, sum, dp);
    return dp[sum] = min(take, nontake);
}

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int ans = calculation(0, n, dp);
    cout << (ans == INT_MAX / 2 ? -1 : ans) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
