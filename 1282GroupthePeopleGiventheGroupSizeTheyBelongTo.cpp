#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        unordered_map<int, vector<vector<int>>> ump;
        for (int i = 0; i < n; ++i)
        {
            int group = groupSizes[i];
            if (ump.find(group) != ump.end() && (ump[group].back().size() < group))
                ump[group].back().push_back(i);
            else
            {
                vector<int> t;
                t.push_back(i);
                ump[group].push_back(t);
            }
        }
        vector<vector<int>> ans;
        for (auto x : ump)
        {
            for (auto y : x.second)
                ans.push_back(y);
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