#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define MIN_HEAP priority_queue<int, vector<int>, greater<int>>
class KthLargest
{
    int k;
    vector<int> nums;
    MIN_HEAP mh;
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        this->nums = nums;
        for (auto &x : nums)
        {
            mh.push(x);
            if (mh.size() > k)
                mh.pop();
        }
    }

    int add(int val)
    {
        mh.push(val);
        if(mh.size()>k)
        mh.pop();
        return mh.top();
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