#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> v(26, 0);
        for (char &ch : s)
            v[ch - 'a']++;
        int ans = 0;
        sort(v.begin(), v.end());
        for (int i = 24; i >= 0;--i)
        {   
            if(v[i] >= v[i+1]){
                int originalFreq = v[i];
                v[i] = max(v[i+1] - 1,0);
                ans += originalFreq - v[i];
            }
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