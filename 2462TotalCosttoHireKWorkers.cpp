#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> mh;
        int n = costs.size();

        int i = 0;
        while (i < candidates)
        {
            mh.push({costs[i], 0});
            ++i;
        }

        int j = n - 1;
        while (j>=i && j >= (n - candidates))
        {
            mh.push({costs[j],1});
            --j;
        }
        
        long long int ans = 0;
        while ((k) && (i<=j))
        {
            --k;
            auto curr = mh.top();
            mh.pop();

            ans += curr.first;

            if(curr.second){
                mh.push({costs[j],1});
                --j;
            }
            else {
                mh.push({costs[i],0});
                ++i;
            }
        }

        while (k)
        {
            ans += mh.top().first;
            mh.pop();
            --k;
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