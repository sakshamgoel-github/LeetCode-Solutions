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
    unordered_map<int, TreeNode *> ump;
    unordered_set<int> children;

public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        for (vector<int> t : descriptions)
        {
            if (ump.find(t[0]) == ump.end())
                ump[t[0]] = new TreeNode(t[0]);
            TreeNode *par = ump[t[0]];

            if (ump.find(t[1]) == ump.end())
                ump[t[1]] = new TreeNode(t[1]);
            TreeNode *child = ump[t[1]];

            if (t[2] == 1)
            {
                par->left = child;
            }
            else
            {
                par->right = child;
            }
            children.insert(t[1]);
        }
        for (auto x : ump)
        {
            if (children.find(x.first) == children.end())
                return x.second;
        }
        return nullptr;
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