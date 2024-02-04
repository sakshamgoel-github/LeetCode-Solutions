#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool check(vector<int> &tfreq, vector<int> &sfreq)
    {
        for (int i = 0; i < 52; i++)
        {
            if (tfreq[i] > sfreq[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<int> tfreq(52, false);
        for (int i = 0; i < m; ++i)
        {   if(islower(t[i]))
            tfreq[t[i] - 'a']++;
            else tfreq[t[i] - 'A' + 26]++;
        }
        vector<int> sfreq(52);
        int i = 0, j = 0;
        int starting_index = -1, len = INT_MAX;
        while (j < n)
        {   if(islower(s[j]))
            sfreq[s[j] - 'a']++;
            else sfreq[s[j] - 'A' + 26]++;
            bool ch = check(tfreq, sfreq);
            while (i <= j && ch)
            {
                if ((j - i + 1) < len)
                {
                    len = j - i + 1;
                    starting_index = i;
                }
                if(islower(s[i]))
                sfreq[s[i] - 'a']--;
                else sfreq[s[i] - 'A' + 26]--;
                ++i;
                ch = check(tfreq, sfreq);
            }
            ++j;
        }
        if (starting_index == -1)
            return "";
        return s.substr(starting_index, len);
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