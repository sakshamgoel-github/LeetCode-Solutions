#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0, hi = n - 1, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (target > matrix[mid][0])
            {
                lo = mid + 1;
            }
            else if (target < matrix[mid][0])
            {
                hi = mid - 1;
            }
            else
            {
                return true;
            }
        }
        if(hi == -1)
        return matrix[0][0] == target;
        int row = hi;
        lo = 0, hi = m - 1;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (target > matrix[row][mid])
            {
                lo = mid + 1;
            }
            else if (target < matrix[row][mid])
            {
                hi = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
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