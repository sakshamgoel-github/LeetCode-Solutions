#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n, m, p;
    string s1, s2, s3;
    int t[101][101][201];

public:
    bool solve(int i, int j, int k)
    {
        if (i == n && j == m && k == p)
            return true;

        if (k >= p)
            return false;
        if (t[i][j][k] != -1)
            return t[i][j][k];
        bool res = false;
        if (s1[i] == s3[k])
            res = solve(i + 1, j, k + 1);
        if (res)
            return t[i][j][k] = true;
        if (s2[j] == s3[k])
            res = solve(i, j + 1, k + 1);
        return t[i][j][k] = res;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        n = s1.length();
        m = s2.length();
        p = s3.length();
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
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