#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 10;
int N;
Point office, home;
vector<Point> customers;
int dist[MAX_N + 2][MAX_N + 2];
int dp[MAX_N][1 << MAX_N]; // dp[pos][mask]

struct Point
{
    int x, y;
};

int manhattan(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int tsp(int pos, int mask)
{
    if (mask == (1 << N) - 1)
    {
        return manhattan(customers[pos], home); // all visited → go home
    }

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INT_MAX;
    for (int next = 0; next < N; ++next)
    {
        if (!(mask & (1 << next)))
        {
            int newDist = manhattan(customers[pos], customers[next]);
            ans = min(ans, tsp(next, mask | (1 << next)) + newDist);
        }
    }
    return dp[pos][mask] = ans;
}

int main()
{
    for (int test = 1; test <= 10; ++test)
    {
        cin >> N;
        customers.clear();
        customers.resize(N);

        cin >> office.x >> office.y >> home.x >> home.y;
        for (int i = 0; i < N; ++i)
            cin >> customers[i].x >> customers[i].y;

        int result = INT_MAX;

        for (int i = 0; i < N; ++i)
        {
            memset(dp, -1, sizeof(dp));
            int initialDist = manhattan(office, customers[i]);
            int totalDist = tsp(i, 1 << i) + initialDist;
            result = min(result, totalDist);
        }

        cout << "# " << test << " " << result << endl;
    }
    return 0;
}
