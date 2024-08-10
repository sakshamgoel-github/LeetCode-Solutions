#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<int> locations;
    int finish, N;
    long long int MOD = 1e9 + 7;
    vector<vector<int>>t;

public:
    int solve(int i, int fuel, vector<vector<int>> &t)
    {   
        if (fuel < 0)
            return 0;

        if (i == finish && fuel == 0)
        {
            return 1;
        }
        
        if(t[i][fuel] != -1)
        return t[i][fuel];

        long long int ans = (i == finish);
        for (int k = 0; k < N; ++k)
        {
            if (k != i)
                ans = (ans + solve(k, fuel - abs(locations[k] - locations[i]),t)) % MOD;
        }

        return t[i][fuel] = (ans % MOD);
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        this->locations = locations;
        this->N = locations.size();
        this->finish = finish;
        t.resize(101,vector<int>(201,-1));
        return solve(start, fuel,t);
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