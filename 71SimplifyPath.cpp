#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.length();
        stack<string> st;
        stack<string> temp;
        int i = 0;
        string ans = "";
        while (i < n)
        {
            string curr_dir = "";
            while (i<n && path[i] != '/')
            {
                curr_dir += path[i];
                ++i;
            }
            ++i;
            if (curr_dir == "..")
            {   
                if(!st.empty())
                st.pop();
            }
            else if (curr_dir == ".")
                continue;
            else if (curr_dir == "/")
                continue;
            else if (curr_dir == "")
                continue;
            else
                st.push(curr_dir);
        }
        while (!st.empty()) //reversing the stack
        {
            temp.push(st.top());
            st.pop();
        }
        
        while (!temp.empty())
        {
            ans += "/";
            ans += temp.top();
            temp.pop();
        }
        if(!ans.length())
        ans+='/';
        return ans;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    string path = "/..";
    cout << obj.simplifyPath(path);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}