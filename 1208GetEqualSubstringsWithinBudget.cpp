#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (s[j] != t[j]) {
                int c = abs(s[j] - t[j]);
                while (i <= j && c > maxCost) {
                    maxCost += abs(s[i] - t[i]);
                    ++i;
                }
                maxCost -= c;
            }
            ans = max(ans, j - i + 1);
            ++j;
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