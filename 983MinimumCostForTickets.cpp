#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
private:
    int index(int i, int addDays, vector<int>&days){
        int n = days.size();
        int limit = addDays + days[i];
        for (int k = i+1; k < n; ++k)
        {
            if(days[k]>=limit)
            return k;
        }
        return n;
    }
    int dp(int ind, vector<int> &days, vector<int> &costs, vector<int> &t, int n)
    {
        if (ind > (n-1)){
            return 0;
        }
        if(t[ind]!=-1)
        return t[ind];
        int ind2 = index(ind,7,days);
        int ind3 = index(ind,30,days);
        int e1 = costs[0] + dp(ind + 1,days,costs,t,n);
        int e2 = costs[1] + dp(ind2,days,costs,t,n);
        int e3 = costs[2] + dp(ind3,days,costs,t,n);
        return t[ind] = min(e1,min(e2,e3));
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> t(366, -1);
        return dp(0,days,costs,t,n);
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