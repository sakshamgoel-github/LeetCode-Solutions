#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    static bool custom(const pair<char, int> &a,const pair<char, int> &b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s)
    {
        int n = s.length();
        vector<pair<char, int>> v(52, {'\0', 0});
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (islower(ch))
            {
                v[ch - 'a'].first = ch;
                v[ch - 'a'].second++;
            }
            else
            {
                v[ch - 'A' + 26].first = ch;
                v[ch - 'A' + 26].second++;
            }
        }
        sort(v.begin(), v.end(), custom);
        string ans = "";
        for (int i = 0; i < 52; ++i)
        {
            if (v[i].second == 0)
                return ans;

            int t = v[i].second;
            while(t--)
            ans += v[i].first;
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