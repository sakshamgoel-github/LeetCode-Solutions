#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
public:
    int runLenCoding(string &s)
    {
        int l = s.length();
        int i = 0, j = 0;
        int ans = 0;
        int curr = 0;
        while (j < l)
        {
            if (s[i] == s[j])
            {
                ++curr;
                ++j;
            }
            else
            {
                ++ans;
                if (curr > 9)
                    ans += 2;
                else if (curr > 1)
                    ans += 1;
                curr = 0;
                i = j;
            }
        }
        ++ans;
        if (curr > 9)
            ans += 2;
        else if (curr > 1)
            ans += 1;
        return ans;
    }
    int solve(int ind, string &t, int k, string &s){
        if(k == 0){
            return runLenCoding(t);
        }
        if(n - ind == k) return runLenCoding(t);
        int choice1 = solve(ind+1, t,--k,s);
        int choice2 = solve(ind+1, t += s[ind], k, s);
        return min(choice1, choice2);

    }
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.length();
        string t = "";
        return solve(0,t,k,s);
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