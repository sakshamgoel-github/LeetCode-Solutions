#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
    vector<vector<int>> t;
    string s1;
    string s2;

public:
    int LCS(int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        else if (t[i][j] != -1)
            return t[i][j];

        else if (s1[i] == s2[j])
            return t[i][j] = 1 + LCS(i - 1, j - 1);

        int ans1 = LCS(i, j - 1);
        int ans2 = LCS(i - 1, j);
        return t[i][j] = max(ans1, ans2);
    }
    int longestPalindromeSubseq(string s)
    {
        this->n = s.length();
        t.resize(n, vector<int>(n, -1));
        this->s1 = s;
        reverse(s.begin(),s.end());
        this->s2 = s;
        return LCS(n - 1, n - 1);
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