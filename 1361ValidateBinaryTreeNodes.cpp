#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class DSU
{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(int n)
    {
        size.resize(n, 1); // Initialize sizes to 1
        parent.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i; // Initialize parents to themselves
        }
    }
    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]); // path compression
    }
    void Union(int u, int v)
    { // union by size
        int ultParent_u = find(u);
        int ultParent_v = find(v);

        if (ultParent_u != ultParent_v)
        {
            parent[ultParent_u] = ultParent_v;
        }
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        DSU obj(n);
        int components = n;
        for (int i = 0; i < n; ++i)
        {
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1)
            {
                if (obj.find(left) != left || left == obj.find(i))
                    return false;
                obj.Union(left, i);
                --components;   
            }
            if (right != -1)
            {
                if (obj.find(right) != right || right == obj.find(i))
                    return false;
                obj.Union(right, i);
                --components;
            }
        }
       return components == 1;
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