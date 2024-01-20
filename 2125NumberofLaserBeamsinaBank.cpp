#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int cntDevices(string &s)
    {
        int ans = 0;
        for (char &ch : s)
        {
            if (ch == '1')
                ++ans;
        }
        return ans;
    }
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        int prev = 0, curr = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            curr = cntDevices(bank[i]);
            ans += curr * prev;
            if(curr > 0){
                prev = curr;
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