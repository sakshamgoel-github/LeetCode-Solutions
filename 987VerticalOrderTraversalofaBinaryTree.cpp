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
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode *, int, int>> q;
        q.push(make_tuple(root, 0, 0));
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr;
                int v, l;
                tie(curr, v, l) = q.front();
                q.pop();
                mp[v][l].insert(curr->val);
                if (curr->left)
                    q.push(make_tuple(curr->left, v - 1, l + 1));
                if (curr->right)
                    q.push(make_tuple(curr->right, v + 1, l + 1));
            }
        }
        for (auto &x : mp)
        {
            vector<int> t;
            for (auto &y : x.second)
            {
                for (int z : y.second)
                {
                    t.push_back(z);
                }
            }
            ans.push_back(t);
        }
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