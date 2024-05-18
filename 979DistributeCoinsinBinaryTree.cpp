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
    int moves;
public:
    int solve(TreeNode *node){
        int l = 0, r = 0;
        if(node -> left)
            l = solve(node -> left);
        if(node -> right)
            r = solve(node -> right);
        moves += abs(l)+abs(r);
        return (l+r+node->val-1);
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        solve(root);
        return moves;
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