#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        int n = words.size();
        vector<vector<int>> v(n, vector<int>(26, 0));
        int ind = 0;
        for (string &word : words)
        {
            for (char &ch : word)
            {
                v[ind][ch - 'a']++;
            }
            ++ind;
        }

        vector<int> used(26, 0);
        for (int i = 0; i < 26;)
        {
            int j = 0;
            while (j < n)
            {
                if ((v[j][i] - used[i]) <= 0)
                    break;
                ++j;
            }
            if (j != n)
            {
                ++i;
                continue;
            }
            char ch = 'a' + i;
            ans.push_back(string(1, ch));
            used[i]++;
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
    Solution obj;
    vector<string> words = {"bella", "label", "roller"};
    vector<string> ans = obj.commonChars(words);
    for (string &a : ans)
        cout << a << "\n";
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}