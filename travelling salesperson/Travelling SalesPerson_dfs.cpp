//dfs diye check korte hbe 
// dfs(node ,count,distance)
//visited node lagbe 
//last giye etao check korte hbe j if there  have connection with current node and home 

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> arr;
int min_dist = INT_MAX;
vector<int> visited;

// Depth-First Search to find the minimum cost Hamiltonian cycle (TSP)
void dfs(int curr, int count, int dist)
{
    if (dist > min_dist)
        return; // Prune paths that already exceed current minimum
    if (count == n)
    {
        if (arr[curr][0] != 0) // Only consider if there's a path back to the start
            min_dist = min(min_dist, dist + arr[curr][0]);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && arr[curr][i] != 0)
        { // Visit unvisited nodes with a valid edge
            visited[i] = 1;
            dfs(i, count + 1, dist + arr[curr][i]);
            visited[i] = 0; // Backtrack
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.clear();
        visited.clear();
        arr.assign(n, vector<int>(n)); // Initialize adjacency matrix
        visited.assign(n, 0);          // Reset visited array
        min_dist = INT_MAX;            // Reset minimum distance

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        visited[0] = 1; // Start DFS from node 0
        dfs(0, 1, 0);

        cout << min_dist << endl; // Output the minimum distance for this test case
    }
    return 0;
}
