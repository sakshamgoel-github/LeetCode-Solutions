#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        int n = nums.size();
        vector<int> averages(n, -1);

        if (2 * k + 1 > n) {
            return averages;
        }
        long long windowSum = 0;
        for (int i = 0; i < (2 * k + 1); ++i) {
            windowSum += nums[i];
        }
        averages[k] = windowSum / (2 * k + 1);

        for (int i = (2 * k + 1); i < n; ++i) {

            windowSum = windowSum - nums[i - (2 * k + 1)] + nums[i];
            averages[i - k] = windowSum / (2 * k + 1);
        }

        return averages;
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