#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        auto compare = [&](int &a, int &b)
        {
            int n1 = __builtin_popcount(a);
            int n2 = __builtin_popcount(b);
            if (n1 == n2)
                return a < b;
            return n1 < n2;
        };
        sort(arr.begin(), arr.end(), compare);
        return arr;
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