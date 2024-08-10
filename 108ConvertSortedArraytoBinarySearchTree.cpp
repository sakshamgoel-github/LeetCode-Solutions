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
    TreeNode *solve(vector<int>& nums, int i, int j){
        if( i > j) return NULL;
        TreeNode *root = new TreeNode(nums[(j + i)/2]);
        root -> left = solve(nums, i, ((j + i)/2)-1);
        root -> right = solve(nums, ((j + i)/2)+1, j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {   
        TreeNode *root = new TreeNode();
        root = solve(nums,0,nums.size()-1);
        return root;
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