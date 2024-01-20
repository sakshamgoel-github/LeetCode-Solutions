#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
    set<string> st;
    vector<int> t;

    bool solve(int i, string& s) {
        if (i >= s.length()) {
            return true;
        }

        if (t[i] != -1) return t[i];
                
        string str = "";
        for (int k = i; k < s.length(); ++k) {
        
            str += s[k];
            if (st.find(str) != st.end()) {
                if (solve(k + 1, s)) return t[i] = true;
            }
        }
        
        return t[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (st.find(s) != st.end()) return true;
        for (auto& str : wordDict) st.insert(str);
        t.resize(s.length() + 1, -1);
        return solve(0, s);
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