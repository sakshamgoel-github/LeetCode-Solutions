#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int t[2][101][101];

public:
    int solve(int person, int i, int M, vector<int> &piles, int n)
    {
        if (i >= n)
            return 0;
        if (t[person][i][M] != -1)
            return t[person][i][M];
        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n-i); x++)
        {
            stones += piles[x + i - 1];
            if (person == 1)
            {
                result = max(result, stones+solve(0, x+i, max(M,x), piles, n));
            }
            else
            {
                result = min(result, solve(1, x+i, max(M,x), piles, n));
            }
        }
        return t[person][i][M] = result;
    }
    int stoneGameII(vector<int> &piles)
    {
        memset(t, -1, sizeof(t));
        return solve(1,0,1,piles,piles.size());
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