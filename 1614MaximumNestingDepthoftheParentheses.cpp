#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        int t = 0;
        for(int i=0;i<n;++i){
            if(s[i] == '('){
                ++t;
            }
            else if(s[i] == ')'){
                --t;
            }
            ans = max(t, ans);
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