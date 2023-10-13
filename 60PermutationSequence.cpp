#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{

public:
    string getPermutation(int n, int k)
    {
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            numbers.push_back(i);
            fact *= i;
        }
        numbers.push_back(n);
        k--;
        string ans = "";
        while (1)
        {
            string t = to_string(numbers[k / fact]);
            ans += t;
            numbers.erase(numbers.begin() + k/fact);
            k = k % fact;
            if(!numbers.size())
            break;
            fact = fact / numbers.size();
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