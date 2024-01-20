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
    int func(TreeNode *curr,bool left){
        if(!curr)
        return 0;
        int leftAns = func(curr->left,true)+!left;
        int rightAns = func(curr->right,false)+left;
        return max(rightAns,leftAns);

    }
    int longestZigZag(TreeNode* root) {
        if(!root)
        return 0;
        int leftAns = func(root->left,true);
        int rightAns = func(root->right,false);
        return max(leftAns,rightAns);
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