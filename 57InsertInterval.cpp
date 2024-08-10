#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        for (; i < n; i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];

            if (newInterval[0] > b)            
                ans.push_back(intervals[i]);
            else if (newInterval[1] < a)            
                break;            
            else{
                newInterval[0] = min(newInterval[0], a);
                newInterval[1] = max(newInterval[1], b);
            }
        }
        ans.push_back(newInterval);
        while (i < n)
        {
            ans.push_back(intervals[i]);
            ++i;
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