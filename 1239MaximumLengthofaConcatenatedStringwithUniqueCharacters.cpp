#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{   unordered_map<string,int>ump;
public:
    bool comp(string &s, string &t)
    {
        vector<int> v(26, 0);
        for (char &x : s)
            v[x - 'a']++;
        for (char &x : t)
            v[x - 'a']++;
        for (int i = 0; i < 26; ++i)
        {
            if (v[i] > 1)
                return false;
        }
        return true;
    }
    int solve(int i, string &t, vector<string> &arr)
    {
        if (i == arr.size())
            return 0;
        
        string p = "";
        p += t + to_string(i);

        if(ump.find(p) != ump.end())
        return ump[p];
        
        int ans1 = solve(i + 1, t, arr), ans2 = 0;
        if (comp(arr[i], t))
        {
            for (char x : arr[i])
                t += x;
            ans2 = solve(i + 1, t, arr) + arr[i].length();
            int l = arr[i].length();
            while(l -- ) t.pop_back();
        }
        
        return (ump[p] = max(ans1, ans2));
    }
    int maxLength(vector<string> &arr)
    {
        string t = "";
       return  solve(0,t,arr);
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