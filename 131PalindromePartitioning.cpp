#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<string>> ans;
    int n;

public:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void solve(int i, vector<string>&t,string &s){
        if(i>=n){
            ans.push_back(t);
            return;
        }
        for (int k = i; k < n; k++)
        {
            if(isPalindrome(s,i,k)){
                t.push_back(s.substr(i,k - i + 1));
                solve(k+1,t,s);
                t.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s)
    {
        n = s.length();
        vector<string>t;
        solve(0,t,s);
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