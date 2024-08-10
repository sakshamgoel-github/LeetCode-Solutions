#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{    
public:
    long long int MOD = 1e9 + 7;
    int t[102][102][102];
    int func(int i, int j, int k,int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        if (i == group.size())
        {
            if ((k >= minProfit) && (j<=n))
                return 1;
            return 0;
        }
        if (j > n)
        return 0;
        if(t[i][j][k]!=-1)
        return t[i][j][k];
        int ans1 = 0,ans2 = 0;
        ans1 = func(i + 1, j, k,n,minProfit,group,profit)%MOD;
        ans2 = func(i + 1, j + group[i], min(k + profit[i],minProfit),n,minProfit,group,profit)%MOD;
        return t[i][j][k] = (ans1 + ans2)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(t,-1,sizeof(t));
        return func(0, 0, 0,n,minProfit,group,profit);
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