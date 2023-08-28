#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    if (m > n)
        return (ninjaAndLadoos(row2, row1, n, m, k));

    int left = k - 1;
    int len = m + n;
    int lo = 0, hi = m;
    while (lo <= hi)
    {
        int mid1 = (lo + hi) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m)
            r1 = row1[mid1];
        if (mid2 < n)
            r2 = row2[mid2];
        if (mid1 >= 1)
            l1 = row1[mid1 - 1];
        if (mid2 >= 1)
            l2 = row2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return min(r1, r2);
        }
        else if (l1 > r2)
            hi = mid1 - 1;
        else
            lo = mid1 + 1;
    }
    return 0;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    cout<<INT_MIN;
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}