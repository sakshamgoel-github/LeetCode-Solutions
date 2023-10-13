#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char digit = '1'; digit <= '9'; digit++)
                    {
                        if (isValid(i, j, board, digit))
                        {
                            board[i][j] = digit;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(int row, int col, vector<vector<char>> &board, char digit)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == digit)
                return false; // Check row
            if (board[i][col] == digit)
                return false; // Check column
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit)
                return false; // Check subgrid
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}