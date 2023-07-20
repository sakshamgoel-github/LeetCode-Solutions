#include <bits/stdc++.h>
using namespace std;

#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{   static bool cmp(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int res = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        for (int r = 1, l = 0; r < n; r++)
        {
            if(intervals[r][0] < intervals[l][1]){
                ++res;
            }
            else l=r;
        }
        return res;
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