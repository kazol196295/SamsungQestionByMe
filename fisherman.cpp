#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;            // number of fishing spots
int gates[3];     // positions of 3 gates
int fishermen[3]; // number of fishermen at each gate
bool visited[11]; // occupied spots
int minDistance = INT_MAX;

void dfs(int idx, vector<int> &order, int totalDist);

void assignFishermen(int depth, int count, int gatePos, int idx, vector<int> &order, int accDist, int totalDist)
{
    if (depth == count)
    {
        dfs(idx + 1, order, totalDist + accDist);
        return;
    }

    for (int d = 0; d <= N; ++d)
    {
        vector<int> candidates;

        if (gatePos - d >= 1 && !visited[gatePos - d])
            candidates.push_back(gatePos - d);
        if (d != 0 && gatePos + d <= N && !visited[gatePos + d])
            candidates.push_back(gatePos + d);

        for (int i = 0; i < candidates.size(); ++i)
        {
            int spot = candidates[i];
            visited[spot] = true;
            assignFishermen(depth + 1, count, gatePos, idx, order, accDist + (d + 1), totalDist);
            visited[spot] = false;
        }

        if (!candidates.empty())
            break;
    }
}

void dfs(int idx, vector<int> &order, int totalDist)
{
    if (idx == 3)
    {
        minDistance = min(minDistance, totalDist);
        return;
    }

    int gatePos = gates[order[idx]];
    int count = fishermen[order[idx]];
    assignFishermen(0, count, gatePos, idx, order, 0, totalDist);
}

int main()
{
    cin >> N;
    for (int i = 0; i < 3; i++)
        cin >> gates[i];
    for (int i = 0; i < 3; i++)
        cin >> fishermen[i];

    vector<int> order = {0, 1, 2};
    do
    {
        fill(visited, visited + 11, false);
        dfs(0, order, 0);
    } while (next_permutation(order.begin(), order.end()));

    cout << minDistance << endl;
    return 0;
}
