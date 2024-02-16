#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
    vector<int> ans;

public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return ans;

        sort(nums.begin(), nums.end());
        vector<int> prevInd(n, -1);
        vector<int> t(n, 1);

        int maxL = 1, maxI = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && t[i] < t[j] + 1) {
                    t[i] = t[j] + 1;
                    prevInd[i] = j;
                    if (maxL < t[i]) {
                        maxL = t[i];
                        maxI = i;
                    }
                }
            }
        }

        while (maxI != -1) {
            ans.push_back(nums[maxI]);
            maxI = prevInd[maxI];
        }
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