#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<char> st1;
        stack<int> st2;
        st2.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st1.push(s[i]);
                st2.push(i);
            }
            else
            {
                if (st1.empty())
                    st2.push(i);
                else
                {
                    st1.pop();
                    st2.pop();
                    int t = i - st2.top();
                    ans = max(t, ans);
                }
            }
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