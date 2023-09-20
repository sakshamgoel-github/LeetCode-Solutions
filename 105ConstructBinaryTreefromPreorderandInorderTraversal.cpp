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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int i = 0;
        vector<int> inorderLeft, inorderRight;
        while (i < inorder.size())
        {
            if (inorder[i] == preorder[0])
                break;
            inorderLeft.push_back(inorder[i]);
            ++i;
        }
        ++i;
        while (i < inorder.size())
        {
            inorderRight.push_back(inorder[i++]);
        }
        preorder.erase(preorder.begin());
        root->left = buildTree(preorder, inorderLeft);
        root->right = buildTree(preorder, inorderRight);
        return root;
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