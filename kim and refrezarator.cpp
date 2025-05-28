#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct Point
{
    int x, y;
};

int N;
Point office, home;
vector<Point> customers;
vector<bool> visited;
int minDist;

int manhattan(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void dfs(Point current, int count, int dist)
{
    if (dist >= minDist)
        return;

    if (count == N)
    {
        dist += manhattan(current, home);
        if (dist < minDist)
            minDist = dist;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(customers[i], count + 1, dist + manhattan(current, customers[i]));
            visited[i] = false;
        }
    }
}

int main()
{
    for (int test = 1; test <= 10; ++test)
    {
        cin >> N;

        customers.clear();
        visited.clear();
        customers.resize(N);
        visited.resize(N, false);
        minDist = INT_MAX;

        // Read locations: office, home, then N customer locations
        cin >> office.x >> office.y >> home.x >> home.y;

        for (int i = 0; i < N; ++i)
        {
            cin >> customers[i].x >> customers[i].y;
        }

        dfs(office, 0, 0);

        cout << "# " << test << " " << minDist << endl;
    }

    return 0;
}
