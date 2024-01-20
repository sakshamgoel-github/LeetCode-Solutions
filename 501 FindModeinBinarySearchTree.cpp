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
    vector<int> res;
    int maxStreak;
    int currStreak;
    int currNum;

public:
    void solve(TreeNode *node)
    {
        if (!node)
        {return;
        }
        solve(node->left);
        if (currNum != node->val)
        {
            currStreak = 1;
            currNum = node->val;
        }
        else
        {
            currStreak += 1;
        }
        if (currStreak > maxStreak)
        {
            res.clear();
            res.push_back(currNum);
            maxStreak = currStreak;
        }
        else if (currStreak == maxStreak)
        {
            res.push_back(currNum);
        }
        solve(node->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        solve(root);
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