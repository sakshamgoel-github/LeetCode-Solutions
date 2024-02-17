#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> mh;
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0)
            {   ++ans;
                continue;
            }

            else if (diff <= bricks)
            {
                bricks -= diff;
                mh.push(diff);
            }

            else if (ladders > 0)
            {
                if (!mh.empty())
                {
                    int past = mh.top();
                    if (diff <= past)
                    {   
                        mh.pop();
                        bricks += past;
                        bricks -= diff;
                        mh.push(diff);
                    }
                }
                --ladders;                
            }
            else
            {
                break;
            }
            ++ans;
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