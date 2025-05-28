#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int N, M, R, C, L;

// Directions: Up, Right, Down, Left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Each pipe type's allowed directions
vector<vector<int>> pipeDirections = {
    {},           // 0: No pipe
    {0, 1, 2, 3}, // 1: All directions
    {0, 2},       // 2: Up, Down
    {1, 3},       // 3: Right, Left
    {0, 1},       // 4: Up, Right
    {1, 2},       // 5: Right, Down
    {2, 3},       // 6: Down, Left
    {0, 3}        // 7: Up, Left
};

// Check if movement from direction `fromDir` is possible into `nextPipe`
bool isConnected(int fromDir, int nextPipeType)
{
    for (int d : pipeDirections[nextPipeType])
    {
        if ((fromDir + 2) % 4 == d)
            return true; // Opposite direction
    }
    return false;
}

int bfs(vector<vector<int>> &grid)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<tuple<int, int, int>> q; // (x, y, time)
    int count = 0;

    q.push({R, C, 1});
    visited[R][C] = true;

    while (!q.empty())
    {
        auto [x, y, time] = q.front();
        q.pop();
        count++;

        if (time == L)
            continue;

        int pipeType = grid[x][y];
        for (int dir : pipeDirections[pipeType])
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
                !visited[nx][ny] && grid[nx][ny] != 0)
            {

                if (isConnected(dir, grid[nx][ny]))
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, time + 1});
                }
            }
        }
    }

    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> R >> C >> L;
        vector<vector<int>> grid(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> grid[i][j];

        if (grid[R][C] == 0)
            cout << 0 << "\n";
        else
            cout << bfs(grid) << "\n";
    }
    return 0;
}
