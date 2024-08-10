#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ones = 0;
        for(int i=0;i<n;++i){
            if(s[i] == '1')
                ++ones;
        }    
        int left_ones = 0, ans = 0;
        for(int i=0;i<n-1;++i){
            if(s[i] == '1')
                ++left_ones;
            int leftScore = i + 1 - left_ones;
            int rightScore = ones - left_ones;
            ans = max(ans, leftScore + rightScore);
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