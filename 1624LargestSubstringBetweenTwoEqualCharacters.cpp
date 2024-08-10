#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int n = s.length();
        int ans = -1;
        vector<int>v(26,-1);
        for (int i = 0; i < n; i++)
        {
            if(v[s[i] - 'a'] == -1) v[s[i] - 'a'] = i;
            else ans = max(ans,i - v[s[i] - 'a'] - 1); 
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