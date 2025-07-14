#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int maxi = -1;
        int minEle = nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i] <= minEle) minEle = nums[i];
            else{
                int t = nums[i] - minEle;
                maxi = max(maxi,t);
            }
        }
        return maxi;
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