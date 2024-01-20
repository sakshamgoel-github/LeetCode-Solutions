#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int>freq(26,0);
        for (int i = 0; i < n; i++)
        {
            for(char ch: words[i]){
                freq[ch - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if(freq[i] % n) return false;
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