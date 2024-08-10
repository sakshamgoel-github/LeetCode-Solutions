#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        queue<int> q;
        int i = 1;
        while (i < 9)
            q.push(i++);
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            if (num >= low && num <= high)
                ans.push_back(num);
            int digit = num%10;
            if(digit == 9) continue;
            ++digit;
            num = num*10+digit;
            if(num <= high)
            q.push(num);
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