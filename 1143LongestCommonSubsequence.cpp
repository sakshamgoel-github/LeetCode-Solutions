#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n, m;
    string text1, text2;
    vector<vector<int>>t;
public:
    int LCS(int i, int j)
    {
        if (i < 0 || j < 0)
            return 0;
        else if(t[i][j]!=-1)
        return t[i][j];
        else if (text1[i] == text2[j])
            return (t[i][j] = 1 + LCS(i - 1, j - 1));

        int ans1 = LCS(i, j - 1);
        int ans2 = LCS(i - 1, j);
        return t[i][j] = max(ans1, ans2);
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        this->n = text1.length();
        this->m = text2.length();
        this->text1 = text1;
        this->text2 = text2;
         t.resize(n, vector<int> (m, -1));
        return LCS(n - 1, m - 1);
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