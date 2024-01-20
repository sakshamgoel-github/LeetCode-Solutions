#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 1)
        return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;

        for (int i = 0; i < n; i++)
        {
            if(!i)
            ans.push_back(intervals[i]);
            else if(ans.back()[1] < intervals[i][0])
            ans.push_back(intervals[i]);
            else {
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
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