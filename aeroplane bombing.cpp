#include <bits/stdc++.h>
using namespace std;

int ans = INT_MIN; // global variable to store the final answer

// Recursive function to explore all paths
void getMaxCoins(vector<vector<int>> &board, int isRowSafe, int cur_row, int cur_col, bool bombUsed, int coins)
{
    int rows = board.size();

    // Out of bounds
    if (cur_row < 0 || cur_col < 0 || cur_col >= 5)
    {
        ans = max(ans, coins);
        return;
    }

    int cell = board[cur_row][cur_col];

    // Cell is coin (1) or empty (0)
    if (cell == 0 || cell == 1)
    {
        int new_coins = coins + (cell == 1 ? 1 : 0);
        int new_isRowSafe = bombUsed ? isRowSafe - 1 : 0;

        getMaxCoins(board, new_isRowSafe, cur_row - 1, cur_col, bombUsed, new_coins);
        getMaxCoins(board, new_isRowSafe, cur_row - 1, cur_col + 1, bombUsed, new_coins);
        getMaxCoins(board, new_isRowSafe, cur_row - 1, cur_col - 1, bombUsed, new_coins);
    }
    // Cell has enemy (2)
    else if (cell == 2)
    {
        if (bombUsed)
        {
            if (isRowSafe <= 0)
            {
                ans = max(ans, coins);
                return;
            }
            else
            {
                getMaxCoins(board, isRowSafe - 1, cur_row - 1, cur_col, bombUsed, coins);
                getMaxCoins(board, isRowSafe - 1, cur_row - 1, cur_col + 1, bombUsed, coins);
                getMaxCoins(board, isRowSafe - 1, cur_row - 1, cur_col - 1, bombUsed, coins);
            }
        }
        else
        {
            // Use the bomb here
            getMaxCoins(board, 4, cur_row - 1, cur_col, true, coins);
            getMaxCoins(board, 4, cur_row - 1, cur_col + 1, true, coins);
            getMaxCoins(board, 4, cur_row - 1, cur_col - 1, true, coins);
        }
    }
}

int main()
{
    int rows;
    cin >> rows;
    vector<vector<int>> board(rows, vector<int>(5));

    // Read grid
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];

    // Start from the spaceship's row (bottom), at positions 1, 2, 3
    getMaxCoins(board, 0, rows - 1, 1, false, 0);
    getMaxCoins(board, 0, rows - 1, 2, false, 0);
    getMaxCoins(board, 0, rows - 1, 3, false, 0);

    cout << "Max_coins : " << ans << endl;
    return 0;
}
