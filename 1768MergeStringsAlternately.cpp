#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        string ans;
        int i=0,j=0;
        while (i<n && j<m)
        {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        while (i<n)
        {
            ans.push_back(word1[i++]);
        }
        while (j<m)
        {
            ans.push_back(word2[j++]);
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