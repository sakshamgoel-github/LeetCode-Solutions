#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    string ans;
    int n;
    vector<bool> v;

public:
    Solution() { ans = ""; }
    void solve(int i, string &t, string &s)
    {
        if (i == n)
        {
            vector<bool> v2;
            for (auto &ch : t)
                v2[ch - 'a'] = true;
            for (int i = 0; i < 26; i++)
            {
                if (v[i] != v2[i])
                    return;
            }
            if (!ans.length())
                ans = t;
            else if (ans.compare(t) > 0)
                ans = t;
        }
        t.push_back(s[i]);
        solve(i + 1, t, s);
        t.pop_back();
        solve(i + 1, t, s);
    }
    string removeDuplicateLetters(string s)
    {
        n = s.length();
        for (auto &ch : s)
            v[ch - 'a'] = true;
        string t = "";
        solve(0, t, s);
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