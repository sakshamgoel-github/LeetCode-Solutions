#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int helper(vector<int> &arr, int ele)
{ // Return the number of elements less than ele
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] <= ele)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}
int median(vector<vector<int>> &matrix, int m, int n)
{
    // Write your code here.
    int ans;
    int lo = 0, hi = 1e9 + 1;
    while (lo <= hi)
    {
        int mid = (hi - lo) / 2 + lo;
        int t = 0;
        for (int i = 0; i < m; i++)
        {
            t += helper(matrix[i],mid);
        }
        if(t <= (n*m)/2) lo = mid + 1;
        else hi = mid - 1;
    }

    return lo;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int> arr = {1, 2, 3, 3};
    cout << helper(arr, 0);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}