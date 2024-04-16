#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;

        for(int i=0;i<n;++i){
            if(s[i] == '*' || s[i] == '(')
                ++open;
            else --open;
            
            if(s[n - 1 - i] == '*' || s[n - 1 - i] == ')')
                ++close;
            else --close;

            if(open < 0 || close < 0)
                return false;
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