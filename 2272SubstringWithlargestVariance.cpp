#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int largestVariance(string s)
    {
        vector<bool> ump(26);
        for (char &ch : s)
        {
            ump[ch - 'a'] = true;
        }
        int ans = 0;
        for (char ch1 = 'a'; ch1 <= 'z'; ++ch1)
        {
            for (char ch2 = 'a'; ch2 <= 'z'; ++ch2)
            {
                if (ch1 == ch2 || !ump[ch1-'a'] || !ump[ch2-'a'])
                    continue;
                for (int r = 0; r < 2; ++r)
                {
                    int cnt1 = 0, cnt2 = 0;
                    for (char ch : s)
                    {
                        cnt1 += ch == ch1;
                        cnt2 += ch == ch2;

                        if (cnt1 < cnt2)
                        {
                            cnt1 = 0;
                            cnt2 = 0;
                        }
                        if (cnt1 > 0 && cnt2 > 0)
                        {
                            ans = max(ans, cnt1 - cnt2);
                        }
                    }
                    reverse(s.begin(), s.end());
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