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
private:
    int ans;

public:
    void dfs(TreeNode *node, int val)
    {   
        if(!node)
        return;
        val = val*10 + node->val;
        if(node->left)
        dfs(node->left,val);
        if(node->right)
        dfs(node->right,val);
        if(!node->left && !node->right)
        ans+=val;
    }
    Solution()
    {
        ans = 0;
    }
    int sumNumbers(TreeNode *root)
    {
        dfs(root,0);
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