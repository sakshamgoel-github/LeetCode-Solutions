#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.length();
            int ans = 0;
            int i=0,j=0;
            unordered_map<char, int>ump;
            while (j<n){
                ump[s[j]]++;
                while (ump.size() == 3){
                    ans += n-j;
                    ump[s[i]]--;
                    if(ump[s[i]] == 0)
                        ump.erase(s[i]);
                    ++i;
                }
                ++j;                
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