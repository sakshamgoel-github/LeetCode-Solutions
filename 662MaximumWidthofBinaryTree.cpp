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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        long long int ans = 0;
        queue<pair<TreeNode *, long long int>> q;
        q.push({root, 1});
        while (!q.empty())
        {
            int n = q.size();
            if(1LL*(q.back().second - q.front().second + 1) > ans)
            ans = q.back().second - q.front().second + 1;
            for (int i = 0; i < n; i++)
            {
                pair<TreeNode *, int> curr = q.front();
                q.pop();
                if (curr.first->left)
                    q.push({curr.first->left, 2LL * curr.second});
                if (curr.first->right)
                    q.push({curr.first->right, 2LL * curr.second + 1});
            }
        }
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