#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{   int t[301][11];
public:
    int solve(vector<int> &jobDifficulty, int ind, int d)
    {
        if (d == 1)
        {
            int ans = 0;
            for(int i=ind;i<jobDifficulty.size();++i) 
                ans = max(ans, jobDifficulty[i]);
            return t[ind][d] = ans;
        }
        if(t[ind][d] != -1) return t[ind][d];
        int maxi = jobDifficulty[ind];
        int ans = 1e6;
        
        for (int i = ind; i <= jobDifficulty.size() - d; i++)
        {
            maxi = max(maxi, jobDifficulty[i]);
            int t = maxi + solve(jobDifficulty, i + 1, d - 1);
            ans = min(ans, t);
        }
        return t[ind][d] = ans;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {   
        if(d > jobDifficulty.size()) return -1;
        memset(t, -1, sizeof(t));
        return solve(jobDifficulty, 0, d);
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