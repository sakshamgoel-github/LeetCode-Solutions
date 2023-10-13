#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    double t[101][101];
    int poured;

public:
    double solve(int i, int j)
    {
        if (i == 0 && j == 0)
            return poured;
        if (i < 0 || j < 0 || i < j)
            return 0;
        if (t[i][j] != -1.0)
            return t[i][j];
        double left_up = max(0.0, (solve(i - 1, j - 1) - 1) / 2.0);
        double right_up = max(0.0, (solve(i - 1, j) - 1) / 2.0);
        return t[i][j] = left_up + right_up;
    }
    double champagneTower(int poured, int query_row, int query_glass)
    {
        for (int i = 0; i < 101; ++i)
        {
            for (int j = 0; j < 101; ++j)
                t[i][j] = -1.0;
        }
        this->poured = poured;
        return min(1.0, solve(query_row, query_glass));
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