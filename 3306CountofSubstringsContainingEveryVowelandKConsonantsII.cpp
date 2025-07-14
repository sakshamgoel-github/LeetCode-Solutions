#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

    class Solution
    {
    public:
    bool isConsonant(char ch)
    {
        ch = tolower(ch); 
        return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
    }
        long long countOfSubstrings(string word, int k)
        {
            long long ans = 0;
            int n = word.length();
            vector<int> v(n);
            v[n - 1] = n + 1;
            int lastIdx=n;
            for (int i = n - 1; i >= 0; --i)
            {
                v[i] = lastIdx;
                lastIdx = isConsonant(word[i]) ? i : lastIdx;
            }
            int i = 0, j = 0, consonants = 0;
            map<char, int> mp;
            while (j < n)
            {
                if (isConsonant(word[j]))
                    ++consonants;
                else
                    mp[word[j]]++;
                
                while (consonants > k)
                {
                    if(isConsonant(word[i]))
                        --consonants;
                    else{
                        mp[word[i]]--;
                        if(mp[word[i]] == 0) mp.erase(word[i]);
                    }
                    ++i;
                }
                while (mp.size() == 5 && consonants == k)
                {
                    ans += 1LL*(v[j]-j);
                    if(isConsonant(word[i]))
                        --consonants;
                    else{
                        mp[word[i]]--;
                        if(mp[word[i]] == 0) mp.erase(word[i]);
                    }
                    ++i;
                }
                ++j;            
    
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