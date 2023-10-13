#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int t[1001][1001];
    int solve(int *p, int n, int i, int prev)
    {
        if (i == n)
        {
            return 0;
        }
        if (prev != -1 && t[i][prev] != -1)
            return t[i][prev];
        int choice1 = 0, choice2 = 0;
        if (prev == -1 || p[prev] < p[i])
            choice1 = solve(p, n, i + 1, i) + p[i];
        choice2 = solve(p, n, i + 1, prev);
        if (prev != -1)
            t[i][prev] = max(choice1, choice2);
        return max(choice1, choice2);
    }

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        memset(t, -1, sizeof(t));
        return solve(arr, n, 0, -1);
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