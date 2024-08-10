#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        int n = details.size();
        for (int i = 0; i < n; i++) {
            if (details[i][11] < '6') {

            } else if (details[i][11] == '6' && details[i][12] > '0') {
                // cout<<details[i]<<"\n";
                ++ans;
            } else if (details[i][11] > '6'){
                // cout<<details[i]<<"\n";
                ++ans;
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
