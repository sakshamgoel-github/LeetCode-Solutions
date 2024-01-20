#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int hi = letters.size() - 1;
        int lo = 0, mid;
        char ans = letters[0];
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (letters[mid] > target)
            {   
                ans = letters[mid];
                hi = mid-1;
            }
            else
                lo = mid + 1;
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