#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++)
        {
            string t = s.substr(0,i);
            if (n % t.length())
                continue;
            
            string repeated = t;
            for (int k = 1; k < n / t.length(); k++)
            {
                repeated += t;
            }
            
            if (repeated == s)
                return true;
        }
        return false;
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