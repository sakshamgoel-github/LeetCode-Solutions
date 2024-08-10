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
    string ans;
    string t = "abcdefghijklmnopqrstuvwxyz";
public:
    void dfs(TreeNode *node, string &curr)
    {   
        if(!node)
            return;
        
        curr += t[node->val];
        if (!node->left && !node->right){
            reverse(curr.begin(), curr.end());
            if (curr < ans || ans == "")
                ans = curr;
            reverse(curr.begin(), curr.end());
        }
        else{
            dfs(node->left, curr);
            dfs(node->right, curr);
        }
        curr.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string curr = "";
        dfs(root, curr);
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