#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.length();
        int left = 0, right = 0, count = 0, res = 0;
        while (right < n)
        {
            if (answerKey[right] == 'F')
                ++count;
            while (count > k)
            {
                if (answerKey[left] == 'F')
                    --count;
                ++left;
            }
            res = max(res, right - left + 1);
            ++right;
        }

        left = 0, right = 0, count = 0;
        while (right < n)
        {
            if (answerKey[right] == 'T')
                ++count;
            while (count > k)
            {
                if (answerKey[left] == 'T')
                    --count;
                ++left;
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res;
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