#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Convert a row to a string representing its zero positions
string getZeroPattern(const vector<int> &row)
{
    string pattern = "";
    for (int bit : row)
    {
        pattern += (bit == 0 ? '1' : '0');
    }
    return pattern;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    unordered_map<string, int> patternCount;
    vector<int> zeroCounts(n);

    // Step 1: Count pattern occurrences
    for (int i = 0; i < n; ++i)
    {
        string pattern = getZeroPattern(matrix[i]);
        patternCount[pattern]++;
    }

    int maxRows = 0;

    // Step 2: Evaluate each pattern
    for (auto &[pattern, count] : patternCount)
    {
        int zeros = 0;
        for (char c : pattern)
            if (c == '1')
                zeros++;

        // Check if it's possible to make all 1's with exactly k flips
        if (zeros <= k && (k - zeros) % 2 == 0)
        {
            maxRows = max(maxRows, count);
        }
    }

    cout << maxRows << endl;
    return 0;
}
