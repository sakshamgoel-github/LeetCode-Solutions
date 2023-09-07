#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        else if (s1[0] == s2[0] && s1[2] == s2[2])
        {
            if (s1[1] == s2[3] && s1[3] == s2[1])
            {
                return true;
            }
        }
        else if (s1[1] == s2[1] && s1[3] == s2[3])
        {
            if (s1[0] == s2[2] && s1[2] == s2[0])
                return true;
        }
        else if(s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] && s1[3] == s2[1])
        return true;
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