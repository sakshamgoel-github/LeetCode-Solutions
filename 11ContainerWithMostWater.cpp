#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0;
        while (left < right)
        {
            int curr = min(height[left],height[right])*(right-left);
            ans = max(ans, curr);
            if(height[left] < height[right]) ++left;
            else --right;
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