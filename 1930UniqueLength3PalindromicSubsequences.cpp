#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int,int>>indices(26,{-1,-1});

        for(int i=0;i<n;++i){
            char ch = s[i];
            int idx = ch - 'a';
            if(indices[idx].first == -1) indices[idx].first = i;
            indices[idx].second = i;
        }  

        int res = 0;
        
        for(char ch = 'a';ch <= 'z';++ch){
            int idx = ch - 'a';
            set<char>st;
            for(int i=indices[idx].first+1;i<indices[idx].second;++i) st.insert(s[i]);
            res += st.size();
        }
        
        return res;
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