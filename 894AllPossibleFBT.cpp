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
    unordered_map<int, vector<TreeNode *>> t;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return vector<TreeNode *>(1, new TreeNode());

        if (t.find(n) != t.end())
        {
            return t[n];
        }
        vector<TreeNode *> res;
        vector<TreeNode *> left;
        vector<TreeNode *> right;

        for (int l = 0; l < n; ++l)
        {
            int r = n - l - 1;
            left = allPossibleFBT(l);
            right = allPossibleFBT(r);
            for (auto x : left)
            {
                for (auto y : right)
                {
                    TreeNode *root = new TreeNode(0, x, y);
                    res.push_back(root);
                }
            }
        }

        return t[n] = res;
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