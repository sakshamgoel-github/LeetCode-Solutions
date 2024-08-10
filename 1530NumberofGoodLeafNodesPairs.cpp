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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
    unordered_map<TreeNode*, TreeNode*>ump;
    set<TreeNode*> leaves;
    void childToParent(TreeNode *root, TreeNode *par) {
        if (!root)
            return;
        ump[root] = par;
        if (!root->left && !root->right)
            leaves.insert(root);        
        childToParent(root->left, root);
        childToParent(root->right, root);
    }

    int getPairs(TreeNode* node1, int distance) {
        int pairs = 0;
        queue<TreeNode*> q;
        unordered_set<TreeNode*>vis;
        q.push(node1);
        vis.insert(node1);
        for(int i=0;i<=distance;++i){
            int n = q.size();
            for(int j=0;j<n;++j){
                TreeNode *curr = q.front();q.pop();
                if(curr != node1 && leaves.find(curr) != leaves.end())
                    ++pairs;
                if(curr -> left && vis.find(curr->left)==vis.end()){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && vis.find(curr->right)==vis.end()){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(ump[curr] && vis.find(ump[curr])==vis.end()){
                    q.push(ump[curr]);
                    vis.insert(ump[curr]);
                }
            }
        }
        return pairs;
    }

public:
    int countPairs(TreeNode* root, int distance) {   
        childToParent(root, NULL);   
        int pairs = 0;
        for (auto &leaf:leaves) {
            pairs += getPairs(leaf, distance);
        }
        return pairs/2;
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