#include <bits/stdc++.h>
using namespace std;

const int MAX = 15;
int rock[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

// Directions: left and right only (horizontal)
int dx[] = {0, 0};
int dy[] = {-1, 1};

// Check if a cell is inside the grid and valid
bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && rock[i][j] != 0;
}

// Try BFS with difficulty level 'level'
bool bfs(int level) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;

    // Start from bottom-left
    q.push({n - 1, 0});
    visited[n - 1][0] = true;

    while (!q.empty()) {
        auto it = q.front(); q.pop();
        int x=it.first,y=it.second;
        if (rock[x][y] == 3)
            return true;

        // Horizontal moves (left/right)
        for (int d = 0; d < 2; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        // Vertical moves within 'level'
        for (int h = 1; h <= level; ++h) {
            // Up
            int up = x - h;
            if (isValid(up, y) && !visited[up][y]) {
                visited[up][y] = true;
                q.push({up, y});
            }
            // Down
            int down = x + h;
            if (isValid(down, y) && !visited[down][y]) {
                visited[down][y] = true;
                q.push({down, y});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    // Input map
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> rock[i][j];

    //Try increasing difficulty level
    for (int level = 0; level <= n; ++level) {
        if (bfs(level)) {
            cout << level << '\n';
            break;
        }
    }
    // int l=0,h=n;
    // while(l<n)
    // {
    //     int mid =l+(h-l)/2;
    //     if(bfs(mid)){
    //         h=mid;
    //     }
    //     else l=mid+1;
    // }
    // cout<<l<<endl;

    return 0;
}
