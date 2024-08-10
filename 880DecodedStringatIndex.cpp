#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long size = 0;
        for (char &ch : s)
        {
            if (isdigit(ch))
                size =size* (ch - '0');
            else
                ++size;
        }
        for (int i = s.length() - 1; i >= 0; --i)
        {
            k = k % size;
            if (!k && isalpha(s[i]))
                return string(1,s[i]);
            if(isalpha(s[i])) --size;
            else size = size/(s[i]-'0');
        }
        return "";
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