#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    set<string> st;
    vector<string> ans;

public:
    void solve(string &s, string &t, int ind)
    {
        if (ind == s.length())
        {
            t.pop_back();
            ans.push_back(t);
        }
        string curr = "";
        string t2 = t;
        for (int k = ind; k < s.length(); k++)
        {
            curr += s[k];
            if (st.find(curr) != st.end())
            {
                t += curr+" ";
                solve(s, t, k + 1);
                t = t2;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string &word : wordDict)
            st.insert(word);
        string t = "";
        solve(s,t,0);
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