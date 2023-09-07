#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>even(26,0);
        vector<int>odd(26,0);
        int n = s1.length();
        for(int i = 0;i<n;++i){
            if(i&1){
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
            else {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
        }
        for(int i = 0;i<26;++i){
            if(odd[i] || even[i])
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