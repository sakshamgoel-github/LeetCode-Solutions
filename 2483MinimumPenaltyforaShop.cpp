#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int Y = 0;
        for (int i = 0; i < customers.length(); i++)
        {
            if (customers[i] == 'Y')
                ++Y;
        }
        int penalty = Y, t = penalty;
        int i = 0; int ans = 0;
        while (i < customers.length())
        {
            if (customers[i] == 'Y')
                --t;
            else
                ++t;
            if(penalty > t){
                ans = i+1;
                penalty = t;
            }
            ++i;
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