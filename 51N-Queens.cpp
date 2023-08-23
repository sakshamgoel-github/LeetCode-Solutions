#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<string>> ans;
    int n;

public:
    bool isSafe(int row, int col, vector<string> &board)
    {
        int Row = row;
        int Col = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            --row;
            --col;
        }

        row = Row;
        col = Col;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            --col;
        }

        row = Row;
        col = Col;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            ++row;
            --col;
        }
        return true;
    }
    void solve(int col, vector<string> &board)
    {
        if (col == n)
        {
            ans.push_back(board);
        }
        else
        {
            for (int row = 0; row < n; row++)
            {
                if (isSafe(row, col, board))
                {
                    board[row][col] = 'Q';
                    solve(col + 1, board);
                    board[row][col] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        vector<string> board(n);
        string row(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = row;
        }
        solve(0, board);
        return ans;
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