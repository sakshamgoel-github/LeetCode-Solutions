#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<int> ans;
int n;
void solve(int i, int sum, vector<int> &num)
{
    if (i >= n)
    {
        ans.push_back(sum);
    }
    else
    {
        solve(i + 1, sum, num);
        solve(i + 1, sum + num[i], num);
    }
}
vector<int> subsetSum(vector<int> &num)
{
    n = num.size();
    solve(0, 0, num);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}