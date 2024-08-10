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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
    bool findPath(TreeNode *root, int target, string &path)
    {
        if (root == NULL)
            return false;
        if (root->val == target)
            return true;
        path.push_back('L');
        if (findPath(root->left, target, path) == true)
            return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, target, path) == true)
            return true;
        path.pop_back();
        return false;
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string src = "";
        findPath(root, startValue, src);
        string des = "";
        findPath(root, destValue, des);
        string res = "";
        int i = 0, j = 0, n1 = src.length(), n2 = des.length();
        while (i < n1 && j < n2)
        {
            if (src[i] == des[j])
            {
                ++i;
                ++j;
            }
            else
                break;
        }
        while (i < n1)
        {
            res.push_back('U');
            ++i;
        }
        while (j < n2)
        {
            res.push_back(des[j]);
            ++j;
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