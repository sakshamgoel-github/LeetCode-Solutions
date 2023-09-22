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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> Inorder(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *extremeRight = curr->left;
                while (extremeRight->right && extremeRight->right != curr)
                {
                    extremeRight = extremeRight->right;
                }
                if (extremeRight->right == NULL)
                {
                    extremeRight->right = curr;
                    curr = curr->left;
                }
                else
                {
                    extremeRight->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
    
    vector<int> Preorder(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *extremeRight = curr->left;
                while (extremeRight->right && extremeRight->right != curr)
                {
                    extremeRight = extremeRight->right;
                }
                if (extremeRight->right == NULL)
                {
                    extremeRight->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    extremeRight->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};

int
main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}