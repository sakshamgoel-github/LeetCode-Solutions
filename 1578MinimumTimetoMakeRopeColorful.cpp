#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i=0,j=0,ans=0, maxi = 0, total = 0;
        while(j < n){
            if(colors[i] == colors[j]){
                total += neededTime[j];
                maxi = max(maxi,neededTime[j]);
                ++j;
            }
            else{
                ans += (total - maxi);
                total = 0;
                maxi = 0;
                i=j;
            }
        }    
        ans += (total - maxi);
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