#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         int n = s.length();
//         for (int i = 0; i < n / 2; i++)
//         {
//             swap(s[i], s[n - i - 1]);
//         }
//         int i = 0, j = 0;
//         while (j < n)
//         {
//             while (j < n && s[j] != ' ')
//             {
//                 ++j;
//             }
//             int k = j - i;
//             for (int a = 0; a < k / 2; a++)
//             {
//                 swap(s[i + a], s[j - a - 1]);
//             }
//             ++j;
//             i = j;
//         }
//         return s;
//     }
// };
class Solution{
    public:
        string reverseWords(string s){
            int n = s.length();
            string t = "";
            stack<string>st;
            for (int i = 0; i < n; i++)
            {
                if(s[i] == ' ' && t.length()){
                    st.push(t);
                    t = "";
                }
                else if(s[i] != ' ') t += s[i];
            }
            if(t.length())
            st.push(t);
            t = "";
            while (!st.empty())
            {
                t += st.top() + " ";
                st.pop();
            }
            t.pop_back();
            return t;
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