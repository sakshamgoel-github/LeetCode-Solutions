#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {   
        int lo = 0, hi = m - 1, mid;
            while (lo < hi)
            {
                mid = (hi-lo ) / 2 + lo;
                if(potions[mid] * 1LL * spells[i] >= success){
                    hi = mid;
                }
                else lo = mid + 1;
            }
            if(hi == (m-1)){
                spells[i] = (spells[i] * 1LL * potions[hi]) >= success;
            }
            else 
            spells[i] = m - hi;

        }
        return spells;
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