#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef pair<int, int> P;
class Solution
{
private:
    priority_queue<P, vector<P>, greater<P>> pq;
    unordered_map<int, int> ump;

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int &num : nums)
        {
            ++ump[num];
        }

        for (auto &x : ump)
        {
            pq.push({x.second, x.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
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
