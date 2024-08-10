#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> hash(26, 0);
        for (char ch : chars)
        {
            hash[ch - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> freq(26, 0);
            for (char ch : words[i])
            {
                freq[ch - 'a']++;
            }
            int k=0;
            while(k < 26){
                if(freq[k] > hash[k]) break;
                ++k;
            }
            if(k == 26) ans += words[i].length();
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