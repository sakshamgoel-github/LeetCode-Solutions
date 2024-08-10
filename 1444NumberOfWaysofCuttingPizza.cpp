#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
private:
    long long MOD = 1e9 + 7;
    int n, m;
    int appleCount[51][51] = {0};
    int t[51][51][11];

   long long int solve(int i, int j, int k)
    {
        if (appleCount[i][j] < k)
            return 0;
        if (k == 1)
        {
            t[i][j][k] = appleCount[i][j] >= 1;
            return t[i][j][k];
        }

        if (t[i][j][k] != -1)
            return t[i][j][k];

       long long  int ans = 0;
        for (int h = i + 1; h < n; h++)
        {
            int lowerSlice = appleCount[h][j];
            int upperSlice = appleCount[i][j] - lowerSlice;

            if (upperSlice >= 1 && lowerSlice >= k - 1)
                ans += solve(h, j, k - 1);
        }
        for (int v = j + 1; v < m; v++)
        {
            int rightHalf = appleCount[i][v];
            int leftHalf = appleCount[i][j] - rightHalf;

            if (leftHalf >= 1 && rightHalf >= k - 1)
                ans += solve(i, v, k - 1);
        }
        ans = ans % MOD;
        return t[i][j][k] = ans;
    }

public:
    int ways(vector<string> &pizza, int k)
    {
        n = pizza.size();
        m = pizza[0].length();

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                int right, down, diagonal;
                if (j == (m - 1))
                    right = 0;
                else
                    right = appleCount[i][j + 1];

                if (i == (n - 1))
                    down = 0;
                else
                    down = appleCount[i + 1][j];

                if ((i == (n - 1)) || (j == (m - 1)))
                    diagonal = 0;
                else
                    diagonal = appleCount[i + 1][j + 1];

                appleCount[i][j] = (pizza[i][j] == 'A') + right - diagonal + down;
            }
        }
        memset(t,-1,sizeof(t));
        return solve(0, 0, k);
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<string> pizza = {"A..", "AAA", "..."};
    obj.ways(pizza, 3);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}