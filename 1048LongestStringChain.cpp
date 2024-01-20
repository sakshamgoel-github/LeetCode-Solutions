#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{   
    vector<vector<int>>t;
    bool check(string &t, string &s)
    {
        if ((t.length() - s.length()) != 1)
            return false;
        int i = 0;
        for (int j = 0; j < t.length() && i < s.length(); j++)
        {
            if (s[i] == t[j])
                ++i;
        }
        return (i == s.length());
    }
    int solve(int i, int prev, vector<string> &words)
    {
        if (i == words.size())
        {
            return 0;
        }
        if(prev!=-1 && t[i][prev]!=-1) return t[i][prev];
        int ans1 = 0, ans2 = 0;
        ans1 = solve(i + 1, prev, words);
        if (prev == -1 || check(words[i], words[prev]))
        {
            ans2 = solve(i + 1, i, words) + 1;
        }
        if(prev != -1)
        t[i][prev] = max(ans1, ans2);
        return max(ans1, ans2);
    }
    static bool myComp(string &s1, string &s2){
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string> &words)
    {   sort(words.begin(), words.end(), myComp);
        t.resize(words.size()+1, vector<int>(words.size()+1,-1));
        return solve(0, -1, words);
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