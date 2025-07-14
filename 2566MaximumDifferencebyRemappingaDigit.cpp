#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int helper(vector<int> &v)
    {
        int num = 0, tens = 1;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            num += v[i] * tens;
            tens *= 10;
        }
        return num;
    }
    int minMaxDifference(int num)
    {
         vector<int> v;
        int x = num;
        while (x != 0)
        {
            v.push_back(x % 10);
            x /= 10;
        }
        reverse(v.begin(), v.end());
        int d_max = 9;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != 9)
            {
                d_max = v[i];
                break;
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == d_max)
            {
                v[i] = 9;
            }
        }
        int maxi = helper(v);
        
        x = num;
        v.erase(v.begin(),v.end());

        while (x != 0)
        {
            v.push_back(x % 10);
            x /= 10;
        }
        reverse(v.begin(), v.end());
        int d_min = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != 0)
            {
                d_min = v[i];
                break;
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == d_min)
            {
                v[i] = 0;
            }
        }
        int mini = helper(v);

        return (maxi - mini);
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