#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> v(2);
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5)
                ++v[0];
            else if (bills[i] == 10) {
                if (v[0] == 0)
                    return false;
                --v[0];
                ++v[1];
            } else {
                if (v[0] == 0)
                    return false;
                if(v[1] != 0){
                    --v[0];
                    --v[1];
                }
                else if(v[0] >= 3){
                    v[0] -= 3;
                }
                else return false;
            }
            // cout<<i<<":"<<v[0]<<" "<<v[1]<<endl;
        }
        return true;
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