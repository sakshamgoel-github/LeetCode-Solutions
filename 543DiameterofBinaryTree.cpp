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

class Solution {
    int diameter;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        calculateHeight(root);
        return diameter;
    }

private:
    int calculateHeight(TreeNode* node) {
        if (!node) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};;

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}