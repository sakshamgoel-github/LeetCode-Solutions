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
public:
    TreeNode *solve(vector<int> &preorder, int i, int j)
    {
        if (i > j)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i]);
        int k = i+1;
        while (k <= j)
        {
            if (preorder[k] > preorder[i])
                break;
            ++k;
        }
        root->left = solve(preorder, i+1, k-1);
        root->right = solve(preorder, k, j);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return solve(preorder, 0, preorder.size() - 1);
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