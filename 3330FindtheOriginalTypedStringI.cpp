#include <bits/stdc++.h>    
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, n = word.length();
        int i = 0, j = 1;
        for (; j < n; ++j) {
            if (word[i] != word[j]) {
                ans += j - i - 1;
                i = j;
            }
        }
        ans += j - i - 1;
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