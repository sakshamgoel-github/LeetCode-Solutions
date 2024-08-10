#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<string> hash = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int N;
    string digits;
    vector<string> ans;

public:
    void solve(int i, string &t)
    {
        if (i == N)
        {
            ans.push_back(t);
        }
        else
        {
            if (digits[i] == '7' || digits[i] == '9')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int index = digits[i] - '0' - 2;
                    t.push_back(hash[index][k]);
                    solve(i + 1, t);
                    t.pop_back();
                }
            }
            else
            {
                for (int k = 0; k < 3; ++k)
                {
                    int index = digits[i] - '0' - 2;
                    t.push_back(hash[index][k]);
                    solve(i + 1, t);
                    t.pop_back();
                }
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        this->N = digits.length();
        if (N == 0)
            return ans;
        this->digits = digits;
        string t;
        solve(0, t);
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