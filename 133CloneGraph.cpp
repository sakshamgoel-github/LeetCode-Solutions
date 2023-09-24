#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    unordered_map<Node *, Node *> ump;
    void dfs(Node *ptr)
    {
        if (ump.find(ptr) != ump.end())
            return;
        Node *t = new Node(ptr->val);
        ump[ptr] = t;
        for (auto x : ptr->neighbors)
            dfs(x);
    }

public:
    Node *cloneGraph(Node *node)
    {   
        if(!node) return NULL;
        dfs(node);
        for (auto p : ump)
        {
            auto par1 = p.first;
            auto par2 = p.second;
            for (auto child1 : par1->neighbors)
            {
                par2->neighbors.push_back(ump[child1]);
            }
        }
        return ump[node];
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