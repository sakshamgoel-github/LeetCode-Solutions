#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<string> ans;

public:
    void solve(string t, int i, int j)
    {
        if (i == 0)
        {
            while (j--)
                t.push_back(')');
            ans.push_back(t);
        }
        else
        {
            if (j > 0)
            {
                t.push_back(')');
                solve(t, i, j - 1);
                t.pop_back();
            }
            t.push_back('(');
            solve(t, i - 1, j + 1);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string t = "";
        solve(t, n, 0);
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