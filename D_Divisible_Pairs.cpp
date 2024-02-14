#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countBeautifulPairs(const vector<int>& a, int x, int y) {
    int n = a.size();
    unordered_map<int, int> remCountX, remCountY;
    long long beautifulPairs = 0;

    for (int i = 0; i < n; ++i) {
        remCountX[a[i] % x]++;
        remCountY[a[i] % y]++;
    }

    for (auto& remX : remCountX) {
        int rX = remX.first;
        int countX = remX.second;
        if (remCountY.find((x - rX) % x) != remCountY.end()) {
            beautifulPairs += (long long)countX * remCountY[(x - rX) % x];
        }
    }

    return beautifulPairs;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long beautifulPairs = countBeautifulPairs(a, x, y);
        cout << beautifulPairs << endl;
    }

    return 0;
}
