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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    vector<int> graph[501];
    vector<int> ans;
    vector<bool>visited;
    int K;

public:
    Solution(){
        visited.resize(501);
    }
    void dfs(int node, int level = 0)
    {
        visited[node] = true;
        if (K == level)
        {
            ans.push_back(node);
            return;
        }
        for (auto &child : graph[node])
        {
            if (!visited[child])
            {
                dfs(child, level + 1);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {   
        if (!root)
        return ans;
        this->K = k;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node -> left)
            {
                q.push(node->left);
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node -> val);
            }
            if (node -> right)
            {
                q.push(node->right);
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node -> val);
            }
        }
        dfs(target->val);
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