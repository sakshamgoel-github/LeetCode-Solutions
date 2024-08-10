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
    vector<TreeNode*>v;
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    TreeNode* build(int l,int r){
        if(l > r)
            return NULL;
        int mid = (r+l)/2;
        TreeNode* node = new TreeNode(v[mid]->val);
        TreeNode* lChild = build(l,mid-1);
        TreeNode* rChild = build(mid+1,r);
        node -> left = lChild;
        node -> right = rChild;
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0,v.size()-1);
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