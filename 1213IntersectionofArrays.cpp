#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        set<int> s;
        while ((i < n1) && (j < n2) && (k < n3))
        {
            if ((A[i] == B[j]) && (A[i] == C[k]))
            {
                ans.push_back(A[i]);
                ++i;
                ++j;
                ++k;
            }
            else
            {
                int maxi = max(A[i], max(B[j], C[k]));
                while ((i < n1) && (A[i] < maxi))
                {
                    ++i;
                }
                while ((j < n2) && (B[j] < maxi))
                {
                    ++j;
                }
                while ((k < n3) && (C[k] < maxi))
                {
                    ++k;
                }
            }
        }
        unsigned size = ans.size();
        for (unsigned i = 0; i < size; ++i)
            s.insert(ans[i]);
        ans.assign(s.begin(), s.end());
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