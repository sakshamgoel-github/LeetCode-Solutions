#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(26,0);
        for(char &ch: s)
        v[ch - 'a']++;

        int ans = 0;
        for(char &ch: s){
            if(v[ch - 'a'] == 1)
            return ans;
            ++ans;
        }
        
        return -1;
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