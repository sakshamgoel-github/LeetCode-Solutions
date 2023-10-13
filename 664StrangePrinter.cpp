#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int N;
    vector<vector<int>>t;
public:
    int solve(int l, int r, string &s){
        if (l == r)
        return 1;

        if (l > r)
        return 0;

        if(t[l][r]!=-1)
        return t[l][r];

        int i = l+1;
        while(i<=r && s[l] == s[i])
        ++i;

        int ans1 = solve(i,r,s)+1;
        int ans2 = 102;
        for(int j=i;j<=r;++j){
            if(s[j] == s[l]){
                int x = solve(i,j-1,s) + solve(j,r,s);
                ans2 = min(ans2,x);
            }
        }
        return t[l][r] = min(ans1,ans2);
    }
    int strangePrinter(string s) {
        this -> N = s.length();
        t.resize(102,vector<int>(102,-1));
        return solve(0,N-1,s);
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