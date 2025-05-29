//solution using recurssion
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







//solution 2 
//using dp
/*
#include <bits/stdc++.h>
using namespace std;
//using dp
int rows;
vector<vector<int>> board;

// Memoization: key is (row, col, bombUsed, isRowSafe)
int dp[1001][5][2][6]; // Use -1 as uninitialized value

int getMaxCoins(int cur_row, int cur_col, bool bombUsed, int isRowSafe) {
    if (cur_row < 0 || cur_col < 0 || cur_col >= 5)
        return 0;

    int &res = dp[cur_row][cur_col][bombUsed][isRowSafe];
    if (res != -1) return res;

    int cell = board[cur_row][cur_col];
    int maxCoins = 0;

    if (cell == 0 || cell == 1) {
        int coinsHere = (cell == 1 ? 1 : 0);
        int newSafe = bombUsed ? isRowSafe - 1 : 0;

        maxCoins = coinsHere + max({
            getMaxCoins(cur_row - 1, cur_col, bombUsed, newSafe),
            getMaxCoins(cur_row - 1, cur_col - 1, bombUsed, newSafe),
            getMaxCoins(cur_row - 1, cur_col + 1, bombUsed, newSafe)
        });
    }
    else if (cell == 2) {
        if (bombUsed) {
            if (isRowSafe <= 0) return 0;
            maxCoins = max({
                getMaxCoins(cur_row - 1, cur_col, bombUsed, isRowSafe - 1),
                getMaxCoins(cur_row - 1, cur_col - 1, bombUsed, isRowSafe - 1),
                getMaxCoins(cur_row - 1, cur_col + 1, bombUsed, isRowSafe - 1)
            });
        } else {
            maxCoins = max({
                getMaxCoins(cur_row - 1, cur_col, true, 4),
                getMaxCoins(cur_row - 1, cur_col - 1, true, 4),
                getMaxCoins(cur_row - 1, cur_col + 1, true, 4)
            });
        }
    }

    return res = maxCoins;
}

int main() {
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++) {
        cin >> rows;
        board.assign(rows, vector<int>(5));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> board[i][j];

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < 5; ++j)
                for (int b = 0; b < 2; ++b)
                    for (int s = 0; s < 6; ++s)
                        dp[i][j][b][s] = -1;

        int result = max({
            getMaxCoins(rows - 1, 1, false, 0),
            getMaxCoins(rows - 1, 2, false, 0),
            getMaxCoins(rows - 1, 3, false, 0)
        });

        cout << "#" << x << " " << result << endl;
    }
    return 0;
}
*/
