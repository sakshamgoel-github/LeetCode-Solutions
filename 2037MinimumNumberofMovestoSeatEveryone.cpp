#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int>s(101);
        vector<int>st(101);
        for(int i=0;i<seats.size();++i){
            s[seats[i]]++;
            st[students[i]]++;
        }
        int i=1, j=1;
        int ans = 0;
        while(j < 101 && i < 101){
            if(st[j] && s[i]){
                ans += abs(j-i);
                --st[j];
                --s[i];
            }
            if(st[j] == 0)
                ++j;
            if(s[i] == 0)
                ++i;
        }
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