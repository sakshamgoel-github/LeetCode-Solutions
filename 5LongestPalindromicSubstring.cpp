#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Manacher
{
    string t;
    vector<int> p;
    void build()
    {
        int n = t.length();
        int C = 0, R = 0; // Center and right boundary of the current palindrome
        p.resize(n,0);
        for (int i = 1; i < n - 1; i++)
        {
            int mirr = 2 * C - i;

            if (i < R)
            {
                p[i] = min(R - i, p[mirr]);
            }

            int a = i + (1 + p[i]);
            int b = i - (1 + p[i]);

            while (t[a] == t[b])
            {
                p[i]++;
                a++;
                b--;
            }

            if (i + p[i] > R)
            {
                C = i;
                R = i + p[i];
            }
        }
    }

public:
    Manacher(string s)
    {
        t = "^";
        for (char ch : s)
        {
            t += "#";
            t += ch;
        }
        t += "#$";
        build();
    }
    vector<int> get() { return p; }
};

class Solution
{
public:
    string longestPalindrome(string s)
    {
        Manacher obj(s);
        
        vector<int> p = obj.get();
        int n = p.size();

        int max_len = 0;
        int center_index = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (p[i] > max_len)
            {
                max_len = p[i];
                center_index = i;
            }
        }

        int start = (center_index - max_len) / 2;
        return s.substr(start, max_len);
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