#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {    
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows, cols;
        rows = points.size();
        cols = points[0].size();
        vector<long long> prev;
        for (int i = 0; i < cols; ++i) {
            prev.push_back(points[0][i] * 1LL);
        }

        for (int r = 1; r < rows; ++r) {
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            leftMax[0] = prev[0];
            for (int i = 1; i < cols; ++i) {
                leftMax[i] = max(prev[i], leftMax[i - 1] - 1);
            }
            rightMax[cols - 1] = prev[cols - 1];
            for (int i = cols - 2; i >= 0; --i) {
                rightMax[i] = max(prev[i], rightMax[i + 1] - 1);
            }
            vector<long long> curr(cols);
            for (int i = 0; i < cols; ++i) {
                curr[i] = points[r][i] + max(leftMax[i], rightMax[i]);
            }
            prev = curr;
        }
        long long ans = 0;
        for (long long x : prev)
            ans = max(ans, x);
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