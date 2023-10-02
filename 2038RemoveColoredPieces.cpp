#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int a = 0, b = 0;
        int n = colors.length();
        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i - 1] == colors[i] && colors[i + 1] == colors[i])
            {
                if(colors[i] == 'A') ++a;
                else ++b;
            }
        }
        return (a > b);
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