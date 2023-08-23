#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string reorganizeString(string s)
    {
        vector<int> v(26, 0);
        int n = s.length();
        for (char &x : s)
        {
            v[x - 'a']++;
            if (v[x - 'a'] > (n + 1) / 2)
                return "";
        }
        priority_queue<pair<int, char>> mh;
        for (int i = 0; i < 26; ++i)
        {   
            if(!v[i])
            continue;
            char ch = 'a' + i;
            mh.push({v[i], ch});
        }
        string ans = "";
        while (mh.size() > 1)
        {
            pair<int, char> P1 = mh.top();
            mh.pop();
            pair<int, char> P2 = mh.top();
            mh.pop();
            ans.push_back(P1.second);
            ans.push_back(P2.second);
            --P1.first;
            --P2.first;
            if (P1.first)
                mh.push(P1);
            if (P2.first)
                mh.push(P2);
        }
        if (!mh.empty())
            ans.push_back(mh.top().second);
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