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

class BSTIterator {
	
	TreeNode *root;
	stack<TreeNode*>st;

public:
    BSTIterator(TreeNode* root) {
    	this->root = root;
    	TreeNode *curr = root;
    	while(curr){
    		st.push(curr);
    		curr = curr->left;
    	}
    }
    
    int next() { 
        TreeNode *ele = st.top();
        st.pop();
        TreeNode *curr = ele->right;
        while(curr){
        	st.push(curr);
        	curr = curr -> left;
        }
        return ele -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}