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
    bool isLeaf(TreeNode *node)
    {
        if (node->left || node->right)
            return false;
        return true;
    }
    void leftBoundary(TreeNode *node, vector<int> &res)
    {
        while (node)
        {
            if (!isLeaf(node))
                res.push_back(node->val);
            if (node->left)
                node = node->left;
            else
                node = node->right;
        }
    }
    void rightBoundary(TreeNode *node, vector<int> &res)
    {
        vector<int> t;
        while (node)
        {
            if (!isLeaf(node))
                t.push_back(node->val);
            if (node->right)
                node = node->right;
            else
                node = node->left;
        }
        for (int i = t.size() - 1; i >= 0; --i)
        {
            res.push_back(t[i]);
        }
    }
    void leafBoundary(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;
        if (isLeaf(node))
            res.push_back(node->val);
        leafBoundary(node->left, res);
        leafBoundary(node->right, res);
    }
    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        if (!isLeaf(root))
            res.push_back(root->val);
        leftBoundary(root->left, res);
        leafBoundary(root, res);
        rightBoundary(root->right, res);
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