#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected;
        expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for(int i=0;i<heights.size();++i){
            if(heights[i]!=expected[i])
                ++ans;
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