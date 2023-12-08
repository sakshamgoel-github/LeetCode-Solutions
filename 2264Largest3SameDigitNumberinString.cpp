#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int n = num.length();
        char maxi = ' ';
        for (int i = 0; i < n - 2; i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
                maxi = max(maxi, num[i]);
        }
        if(maxi == ' ') return "";
        return string(3,maxi);
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