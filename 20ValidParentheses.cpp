#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char &ch: s){
            if(ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
            else{
                if(st.empty())
                    return false;
                if(ch == ')' && st.top() != '(')
                    return false;
                if(ch == '}' && st.top() != '{')
                    return false;
                if(ch == ']' && st.top() != '[')
                    return false;
            st.pop();
            }
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