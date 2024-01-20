#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int solve(int ind, int prev, vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        if (ind == startTime.size())
            return 0;
        int p1 = 0, p2 = 0;
        p1 = solve(ind + 1, prev, startTime, endTime, profit);
        if (prev == -1 || startTime[ind] >= endTime[prev])
            p2 = solve(ind + 1, ind, startTime, endTime, profit) + profit[ind];
        return max(p1, p2);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        return solve(0,-1,startTime,endTime, profit);
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