#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> t;

public:
    int isValid(vector<int> &nums, int val)
    {   
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(nums[mid] == val)
            return mid;
            else if(nums[mid] > val)
            hi = mid - 1;
            else lo = mid + 1;
        }
        if(nums[lo] == val)
        return lo;
        return -1;
    }
    bool solve(int i, int k, vector<int> &stones)
    {
        if (i == stones.size() - 1)
            return true;

        if (t[i][k] != -1)
            return t[i][k];

        bool choice1 = false, choice2 = false, choice3 = false;
        int a = isValid(stones, stones[i] + k - 1);
        int b = isValid(stones, stones[i] + k);
        int c = isValid(stones, stones[i] + k + 1);

        if(k!=0){
        if ((k - 1) != 0 && a != -1)
            choice1 = solve(a, k - 1, stones);
        if (b != -1)
            choice2 = solve(b, k, stones);
        }if (c != -1)
            choice3 = solve(c, k + 1, stones);
        return t[i][k] = choice1 | choice2 | choice3;
    }

    bool canCross(vector<int> &stones)
    {
        t.resize(2001, vector<int>(2001, -1));
        return solve(0, 0, stones);
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