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
    int ans;
public:
    pair<int,int> postOrder(TreeNode *node){
        if(node){
            pair<int,int>left = postOrder(node->left);
            pair<int,int>right = postOrder(node->right);
            int cnt = 1,sum = node->val;
            sum += left.first+right.first;
            cnt += left.second+right.second;
            if((sum/cnt) == node->val) ++ans;
            return {sum,cnt};
        }
        return {0,0};
    }
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
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