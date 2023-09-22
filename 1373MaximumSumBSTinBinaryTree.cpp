#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int MINI = -40001;
    int MAXI = 40001;
    struct S
    {
        int sum;
        int largestLeft;
        int smallestRight;
        S(int sum, int largestLeft, int smallestRight)
        {
            this->sum = sum;
            this->largestLeft = largestLeft;
            this->smallestRight = smallestRight;
        }
        S() {}
    };
    int ans = 0;
public:
    S solve(TreeNode *root)
    {
        if (!root)
            return S(0, MINI, MAXI);

        S left = solve(root->left);
        S right = solve(root->right);

        if (left.largestLeft >= root->val || right.smallestRight <= root->val)
        {
            return S(max(left.sum, right.sum), MAXI, MINI);
        }

        else
        {
            S t;
            t.sum = left.sum + right.sum + root->val;
            t.largestLeft = max({right.largestLeft, root->val});
            t.smallestRight = min(left.smallestRight, root->val);
            ans = max(ans, t.sum);
            return t;
        }
    }
    int maxSumBST(TreeNode *root)
    {
        solve(root);
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