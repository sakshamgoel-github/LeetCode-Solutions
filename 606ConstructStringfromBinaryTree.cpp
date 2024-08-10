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
    string tree2str(TreeNode* root) {
       if(!root) return "";
       string l = tree2str(root -> left);
       string r = tree2str(root -> right);
       string ans = "";
       string v = to_string(root -> val);
       ans+=v;
       if(r.length()){
           ans.push_back('(');
           ans+=l;
           ans.push_back(')');
           ans.push_back('(');
           ans+=r;
           ans.push_back(')');
       } 
       else{
           if(l.length()){
           ans.push_back('(');
           ans+=l;
           ans.push_back(')');   
           }
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