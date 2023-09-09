#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int i = 0;
        
        // Skip leading whitespace
        while (i < n && s[i] == ' ')
        {
            ++i;
        }
        
        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // Initialize result
        long long int ans = 0;
        
        // Convert characters to integers
        while (i < n && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');
            
            // Check for overflow
            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;
            
            ++i;
        }

        // Apply sign
        return ans * sign;
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