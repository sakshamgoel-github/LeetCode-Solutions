#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char>mp1;
        unordered_map<char, char>mp2;

        for(int i=0;i<s.length();++i){
            if(mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end()){
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else if(mp1.find(s[i]) == mp1.end() || mp2.find(t[i]) == mp2.end()) {
                return false;
            }
            else if (mp1[s[i]] != t[i]){
                return false;
            }
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