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

class BSTIterator
{
    TreeNode *root;
    stack<TreeNode *> st;
    const bool reverse;

public:
    BSTIterator(TreeNode *root, bool rev):reverse(rev)
    {
        this->root = root;
        TreeNode *curr = root;
        if (!reverse)
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
        }
        else
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->right;
            }
        }
    }
    bool hasNext()
    {
        return st.empty();
    }
    int next()
    {
        TreeNode *ele = st.top();
        st.pop();
        if (!reverse)
        {
            TreeNode *curr = ele->right;
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
        }
        else
        {
            TreeNode *curr = ele->left;
            while (curr)
            {
                st.push(curr);
                curr = curr->right;
            }
        }
        return ele->val;
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if((i+j) == k) return true;
            else if((i+j) < k) i = l.next();
            else j = r.next();
        }
        return false;
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