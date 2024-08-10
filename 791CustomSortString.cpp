#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26,0);
        for(char &x: s){
            freq[x - 'a']++;
        }
        int i=0;
        for(char &x:order){
            while(freq[x-'a']){
                s[i] = x;
                ++i;
                freq[x-'a']--;
            }
        }
        for (int k = 0; k < 26; k++)
        {
            while(freq[k]--){
                s[i] = 'a'+k;
                ++i;
            }
        }
        return s;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    string order = "exv";
    string s = "xwvee";
    obj.customSortString(order,s);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}