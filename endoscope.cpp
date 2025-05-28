
#include <bits/stdc++.h>
using namespace std;

int row, col, X, Y, L;
vector<vector<int>> mapp;
vector<vector<bool>> visited;

// Directions: {dx, dy}, direction check function for current and next cell
const int dx[] = {0, 0, -1, 1}; // left, right, up, down
const int dy[] = {-1, 1, 0, 0};

bool valid(int x, int y)
{
    return (x >= 0 && x < row && y >= 0 && y < col);
}

// Pipe direction functions
bool left(int x, int y)
{
    int type = mapp[x][y];
    return (type == 1 || type == 3 || type == 6 || type == 7);
}
bool right(int x, int y)
{
    int type = mapp[x][y];
    return (type == 1 || type == 3 || type == 4 || type == 5);
}
bool up(int x, int y)
{
    int type = mapp[x][y];
    return (type == 1 || type == 2 || type == 4 || type == 7);
}
bool down(int x, int y)
{
    int type = mapp[x][y];
    return (type == 1 || type == 2 || type == 6 || type == 5);
}

int solve(int x, int y, int l)
{
    queue<tuple<int, int, int>> q;
    visited[x][y] = true;
    q.push({x, y, l});

    int ans = 0;

    while (!q.empty())
    {
        auto [cx, cy, cl] = q.front();
        q.pop();

        if (cl == 0)
            continue;
        ans++;

        // Check each direction
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (!valid(nx, ny) || visited[nx][ny] || mapp[nx][ny] == 0)
                continue;

            bool canMove = false;
            if (dir == 0 && left(cx, cy) && right(nx, ny))
                canMove = true; // left
            if (dir == 1 && right(cx, cy) && left(nx, ny))
                canMove = true; // right
            if (dir == 2 && up(cx, cy) && down(nx, ny))
                canMove = true; // up
            if (dir == 3 && down(cx, cy) && up(nx, ny))
                canMove = true; // down

            if (canMove)
            {
                visited[nx][ny] = true;
                q.push({nx, ny, cl - 1});
            }
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> row >> col >> X >> Y >> L;

        mapp.assign(row, vector<int>(col));
        visited.assign(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                cin >> mapp[i][j];

        if (mapp[X][Y] > 0)
            cout << solve(X, Y, L) << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
