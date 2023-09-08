#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        int l = 0;
        string ans = "";
        for (int i = 0; i < n; i++)
        {   string t = "";
            for (int j = i; j < n; j++)
            {
                t += s[j];
                if(isPalindrome(t) && ((j - i + 1) > l)){
                    l = (j - i + 1);
                    ans = t;
                }
            }            
        }
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