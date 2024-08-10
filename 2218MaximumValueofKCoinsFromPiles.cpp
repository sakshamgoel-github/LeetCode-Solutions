#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
    vector<vector<int>>t;
    vector<vector<int>>piles;
public:
    int func(int i, int k)
    {
        if (!k || i >= n)
            return 0;
        if(t[i][k]!=-1)
        return t[i][k];
        int ans1 = func(i + 1, k); //not choosing any coin from current pile
        int curr = 0, ans2 = 0;
        for (int j = 0; j < k && j < piles[i].size(); j++)
        {
            curr += piles[i][j];
            int temp = curr + func(i + 1, k - j - 1);
            ans2 = max(ans2, temp);
        }
        return t[i][k] = max(ans1, ans2);
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        n = piles.size();
        this->piles = piles;
        t.resize(n+1,vector<int>(k+1,-1));
        return func(0, k);
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<int>> piles = {{1, 100, 3}, {7, 8, 9}};
    int k = 2;
    cout << obj.maxValueOfCoins(piles, k);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}