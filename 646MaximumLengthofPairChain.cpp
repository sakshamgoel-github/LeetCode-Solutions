#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

//Top Down
class Solution
{
    vector<vector<int>> t;

public:
    int solve(int i, int prev, vector<vector<int>> &pairs)
    {
        if (i == pairs.size())
            return 0;

        if (prev != -1 && t[i][prev] != -1)
            return t[i][prev];
        
        int choice1 = 0;
        if (prev == -1 || pairs[i][0] > pairs[prev][1])
            choice1 = 1 + solve(i + 1, i, pairs);
        int choice2 = solve(i + 1, prev, pairs);

        if (prev != -1)
            t[i][prev] = max(choice1, choice2);

        return max(choice1, choice2);
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {   
        sort(pairs.begin(),pairs.end());
        t.resize(pairs.size() + 1, vector<int>(pairs.size() + 1, -1));
        return solve(0, -1, pairs);
    }
};

//Bottom Up
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {   
        int ans = 1;   
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>t(pairs.size() + 1,1);
        for(int i = 0;i<n;++i){
            for(int j=0;j<i;++j){
                if(pairs[i][0] > pairs[j][1]){
                    t[i] = max(t[i],t[j]+1);
                }
                ans = max(ans,t[i]);
            }
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