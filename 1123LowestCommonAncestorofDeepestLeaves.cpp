#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        pair<TreeNode*, int> lca(TreeNode *node){
            if(!node)
                return {NULL,0};
            auto left = lca(node->left);
            auto right = lca(node->right);
            
            if(left.second == right.second)
                return {node, right.second+1};
            else if(left.second > right.second)
                return {left.first, left.second+1};
            return {right.first, right.second+1};
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return lca(root).first;
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