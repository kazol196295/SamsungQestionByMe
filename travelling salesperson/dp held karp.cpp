#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int tsp(int curr, int mask) {
    if (mask == (1 << n) - 1) {
        // All cities visited, return to start if possible
        return dist[curr][0] ? dist[curr][0] : INF;
    }

    if (dp[curr][mask] != -1) return dp[curr][mask];

    int ans = INF;
    for (int next = 0; next < n; ++next) {
        if (!(mask & (1 << next)) && dist[curr][next] != 0) {
            int new_mask = mask | (1 << next);
            int cost = dist[curr][next] + tsp(next, new_mask);
            ans = min(ans, cost);
        }
    }
    return dp[curr][mask] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        dist.assign(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> dist[i][j];

        int size = 1 << n;
        dp.assign(n, vector<int>(size, -1));
        cout << tsp(0, 1) << endl; // Start from node 0 with only 0 visited
    }
    return 0;
}
