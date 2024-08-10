#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        int n = s.length();
        int m = goal.length();

        if (m != n)
            return false;

        int i = 0;
        while (i < n)
        {
            hash1[s[i] - 'a']++;
            hash2[goal[i] - 'a']++;
            ++i;
        }

        for (int k = 0; k < 26; k++)
        {
            if (hash1[k] != hash2[k])
                return false;
        }

        int count = 0;
        i = 0;
        while (i < n)
        {
            if (s[i] != goal[i])
                ++count;
            ++i;
        }
        if (!count)
        {
            for (auto &x : hash1)
            {
                if (x >= 2)
                    return true;
            }
        }
        return count == 2;
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