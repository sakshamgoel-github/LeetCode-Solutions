#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ump(256,-1);
        int l = 0;
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (ump[s[i]]!=-1){
                l = max(ump[s[i]] + 1, l);
            }
            ump[s[i]] = i;
            ans = max(ans, i - l + 1);
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