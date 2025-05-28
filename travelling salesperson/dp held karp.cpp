#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> dist;

int tsp()
{
    int size = 1 << n; // 2^n
    vector<vector<int>> dp(size, vector<int>(n, INF));
    dp[1][0] = 0; // Start at node 0 with only node 0 visited

    for (int mask = 1; mask < size; ++mask)
    {
        for (int u = 0; u < n; ++u)
        {
            if (!(mask & (1 << u)))
                continue; // u is not in mask
            for (int v = 0; v < n; ++v)
            {
                if ((mask & (1 << v)) || dist[u][v] == 0)
                    continue; // v already visited or no edge
                int next_mask = mask | (1 << v);
                dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int min_cost = INF;
    for (int i = 1; i < n; ++i)
    {
        if (dist[i][0] == 0)
            continue;
        min_cost = min(min_cost, dp[(1 << n) - 1][i] + dist[i][0]);
    }
    return min_cost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        dist.assign(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> dist[i][j];
        cout << tsp() << endl;
    }
    return 0;
}
