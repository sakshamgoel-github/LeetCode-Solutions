#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> ans;
    int N;

public:
    void solve(int ele, vector<int> &t, int k)
    {
        if (!k)
        {
            ans.push_back(t);
        }
        else if (ele > N)
        {
        }
        else
        {
            t.push_back(ele);
            solve(ele + 1, t, k - 1);
            t.pop_back();
            solve(ele + 1, t, k);
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        this->N = n;
        vector<int> t;
        solve(1, t, k);
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