#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0,j=tokens.size()-1;
        sort(tokens.begin(), tokens.end());
        int maxScore=0,score=0;
        while (i<=j)
        {
            if(power >= tokens[i]){
                ++score;
                maxScore = max(maxScore, score);
                power -= tokens[i];
                ++i;
            }
            else if(score >= 1){
                --score;
                power += tokens[j];
                --j;
            }
            else break;
        }
        return maxScore;
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