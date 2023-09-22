#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>>mp;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            mp[s[i]].push_back(i);
        }
        int cnt = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int prev = -1;
            int m = words[i].length();
            int j = 0;
            while (j < m)
            {
                if(mp.find(words[i][j]) == mp.end()) break;
                auto it = upper_bound(mp[words[i][j]].begin(),mp[words[i][j]].end(),prev);
                if(it == mp[words[i][j]].end()) break;
                prev =  *it;
                ++j;
            }
            cnt += (j == m);
        }
        return cnt;
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