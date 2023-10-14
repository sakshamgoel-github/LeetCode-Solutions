#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<int> t;
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        int n = cost.size();
        int a = cost[0],b = cost[1],c;
        for (int i = 2; i < n; i++)
        {
            c = min(a,b) + cost[i];
            a = b;
            b = c;
        }
        return min(a,b);
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