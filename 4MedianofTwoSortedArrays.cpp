#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n2 < n1)
            return (findMedianSortedArrays(nums2, nums1)); // make sure nums1 is less than nums2
        int left = (n1 + n2 + 1) / 2;                      // number of elements to take in left half
        int lo = 0, hi = n1;
        while (lo <= hi)
        {
            int mid1 = (lo + hi) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 >= 1)
                l1 = nums1[mid1 - 1];
            if (mid2 >= 1)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) & 1)
                {
                    return max(l1, l2);
                }
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if (l1 > r2)
            {
                hi = mid1 - 1;
            }
            else
            {
                lo = mid1 + 1;
            }
        }
        return 0;
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