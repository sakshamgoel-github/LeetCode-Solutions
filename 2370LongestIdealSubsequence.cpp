#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int longestIdealString(string s, int k) {
       vector<int>t(26,0);
       int result = 0;
       for(int i=0;i<s.length();++i){
        int curr = s[i] - 'a';
        int left = max(0,curr - k);
        int right = min(25,curr + k);
        int longest = 0;
        for(int j=left;j<=right;++j){
            longest = max(longest, t[j]);
        }
        t[curr] = max(t[curr], longest+1);
        result = max(result,t[curr]);
       } 
       return result;
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