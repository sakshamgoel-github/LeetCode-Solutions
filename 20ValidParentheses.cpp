#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> st;
        int i = 0;
        while (i < n)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.empty())
                    return false;

                char ch = st.top();
                if (ch != '(')
                    return false;

                st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.empty())
                    return false;

                char ch = st.top();
                if (ch != '[')
                    return false;

                st.pop();
            }
            else if (s[i] == '}')
            {
                if (st.empty())
                    return false;

                char ch = st.top();
                if (ch != '{')
                    return false;
                
                st.pop();
            }
            ++i;
        }
        return st.empty();
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