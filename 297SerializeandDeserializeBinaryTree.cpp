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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        queue<TreeNode *> q;
        q.push(root);
        string s = "";
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (!curr)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(curr->val) + ",");
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;
        stringstream s(data);
        string str = "";
        getline(s, str, ',');
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#")
            {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            getline(s, str, ',');
            if (str != "#")
            {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}