#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);


struct Node
{
    Node *links[2];
    bool flag;
    void put(int bit, Node *node)
    {
        this->links[bit] = node;
    }
    Node *get(int bit)
    {
        return this->links[bit];
    }
    void setEnd()
    {
        this->flag = true;
    }
    bool contains(int bit)
    {
        return (this->links[bit] != nullptr);
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (!node->contains(bit))
                node->put(bit, new Node());

            node = node->get(bit);
        }
        node->setEnd();
    }
    int XOR(int num)
    {
        int ans = 0;
        Node *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (node->contains(!bit))
            {
                ans = ans | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie obj;
        int ans = 0;
        for (auto &x : nums)
        {
            obj.insert(x);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = obj.XOR(nums[i]);
            if (temp > ans)
                ans = temp;
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