#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define MIN_HEAP priority_queue<int, vector<int>, greater<int>>
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = 0, sum = 0;
        int n = nums1.size();
        int j = 0;
        while (j < n)
        {
            MIN_HEAP mh;
            sum = 0;
            for (int i = j; i < k; i++)
            {
                sum += nums1[i];
                mh.push(nums2[i]);
            }
            ans = max(ans, mh.top() * 1LL * sum);
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