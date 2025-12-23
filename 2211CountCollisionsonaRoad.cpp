#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        int i = 0, j = directions.length()-1;
        while (i <= j)
        {
            if(directions[i] == 'L')
                ++i;
            else break;
        }
        while (j >= 0)
        {
            if(directions[j] == 'R')
                --j;
            else break;
        }
        while (i <= j)
        {
            if(directions[i] == 'L' || directions[i] == 'R')
                ++ans;
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