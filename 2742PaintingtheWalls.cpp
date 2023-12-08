#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> t;
public:
    int solve(int i, int j, vector<int> &cost, vector<int> &time)
    {
        if (j <= 0)
            return 0;
        if (i == cost.size())
            return 1e9;
        if (t[i][j] != -1)
            return t[i][j];
        int choice1 = cost[i] + solve(i + 1, j - 1 - time[i], cost, time);
        int choice2 = solve(i + 1, j, cost, time);
        return t[i][j] = min(choice1, choice2);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        t.resize(cost.size() + 1, vector<int>(cost.size() + 1, -1));
        return solve(0, cost.size(), cost, time);
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