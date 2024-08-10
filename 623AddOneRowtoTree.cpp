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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val, root, nullptr);
            return newNode;
        }
        queue<TreeNode*>q;
        q.push(root);
        for(int i=2;i<depth;++i){
            int n = q.size();
            for(int i=0;i<n;++i){
                TreeNode *curr = q.front();
                q.pop();
                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);
            }
        }
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            TreeNode *lnode = new TreeNode(val, curr -> left, nullptr);
            TreeNode *rnode = new TreeNode(val, nullptr, curr -> right);
            curr -> left = lnode;
            curr -> right = rnode;
        }
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