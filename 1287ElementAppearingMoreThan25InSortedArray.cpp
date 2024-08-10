#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int findLeftInd(int ele, vector<int> &arr)
    {
        int hi = arr.size() - 1;
        int lo = 0;
        int res = -1, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (arr[mid] == ele)
            {
                res = mid;
                hi = mid - 1;
            }
            else if (arr[mid] < ele)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return res;
    }
    int findRightInd(int ele, vector<int> &arr)
    {
        int hi = arr.size() - 1;
        int lo = 0;
        int res = -1, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (arr[mid] == ele)
            {
                res = mid;
                lo = mid + 1;
            }
            else if (arr[mid] < ele)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return res;
    }
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int freq = n / 4;
        int i = freq;
        while (i < n)
        {
            int l = findLeftInd(arr[i], arr);
            int r = findRightInd(arr[i], arr);
            if ((r - l + 1) > freq)
                return arr[i];
            i = i + freq;
        }
        return -1;
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