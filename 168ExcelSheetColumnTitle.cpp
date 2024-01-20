#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {               
        string ans = "";
        while (columnNumber)
        {
            int t = columnNumber % 26;
            if(!t){
            columnNumber -= 26;
            t = 26;
            }
            char ch = 'A' + t - 1;
            ans += ch;
            columnNumber /= 26;
        }
        reverse(ans.begin(),ans.end());
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
obj.convertToTitle(701);
cout<<endl<<(701%26);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}