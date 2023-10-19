#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0)
        {
            while(i >= 0){
                if(s[i] == '#'){
                    --i;
                    ++skipS;
                }
                else if(skipS){
                    i--;
                    skipS--;
                }
                else break;
            }
            while (j >= 0)
            {
                if(t[j] == '#'){
                    --j;
                    ++skipT;
                }
                else if(skipT){
                    j --;
                    skipT--;
                }
                else break;
            }
            char first = i >= 0 ? s[i]:'$';
            char second = j >= 0 ? t[j]:'$';
            --i; --j;
            if(first != second) return false;
        }
        return true;
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