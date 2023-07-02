#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> row;
        vector<int> col;

        int N = matrix.size();
        int M = matrix[0].size();

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (!matrix[i][j])
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for (int r : row)
        {
            for (int k = 0; k < M; ++k)
                matrix[r][k] = 0;
        }
        for (int c : col)
        {
            for (int k = 0; k < N; ++k)
                matrix[k][c] = 0;
        }
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