#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    cin >> k;

    // Inputting the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    unordered_map<string, int> map;

    // Storing frequency in map
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = 0; j < m; j++)
        {
            temp += char(mat[i][j] + '0');
        }
        map[temp]++;
    }

    int ans = INT_MIN;

    for (auto &entry : map)
    {
        // Counting number of zeros in each row
        int num_zeros = 0;
        for (char ch : entry.first)
        {
            if (ch == '0')
                num_zeros++;
        }
        if (num_zeros <= k && (k - num_zeros) % 2 == 0)
        {
            ans = max(ans, entry.second);
        }
    }

    cout << ans << endl;
    return 0;
}