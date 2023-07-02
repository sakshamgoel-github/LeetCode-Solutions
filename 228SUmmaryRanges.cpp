#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string numToString(int num)
    {
        string ans = "";
        bool flag = false;
        if(num < 0){
            flag = true;
            num*=-1;
        }
        if(!num)
        return "0";
        while (num)
        {
            int n = num % 10;
            num /= 10;

            switch (n)
            {
            case 0:
                ans = "0" + ans;
                break;
            case 1:
                ans = "1" + ans;
                break;
            case 2:
                ans = "2" + ans;
                break;
            case 3:
                ans = "3" + ans;
                break;
            case 4:
                ans = "4" + ans;
                break;
            case 5:
                ans = "5" + ans;
                break;
            case 6:
                ans = "6" + ans;
                break;
            case 7:
                ans = "7" + ans;
                break;
            case 8:
                ans = "8" + ans;
                break;
            case 9:
                ans = "9" + ans;
                break;
            default:
                break;
            }
        }
        if(flag){
            ans.insert(0,"-");
        }
        return ans;
    }
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int size = nums.size();
        int i = 1;
        string lo = numToString(nums[0]), hi = lo;
        while (i < size)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                hi = numToString(nums[i]);
            }
            else
            {
                if (hi == lo)
                {
                    ans.push_back(lo);
                }
                else if (hi != lo)
                {
                    ans.push_back(lo + "->" + hi);
                }
                lo = numToString(nums[i]);
                hi = lo;
            }
            ++i;
        }
        if (hi == lo)
        {
            ans.push_back(lo);
        }
        else if (hi != lo)
        {
            ans.push_back(lo + "->" + hi);
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