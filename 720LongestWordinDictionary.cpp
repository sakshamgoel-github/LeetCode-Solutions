#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct Node
{
    Node *links[26];
    bool flag;
    bool contains(char c)
    {
        return (links[c - 'a'] != nullptr);
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }
    Node *get(char c)
    {
        return links[c - 'a'];
    }
    void setEnd()
    {
        this->flag = true;
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
    void insert(string &word)
    {
        int n = word.length();
        Node *node = root;
        for (int i = 0; i < n; ++i)
        {
            if (!node->contains(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string &word)
    {
        int n = word.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->links[word[i] - 'a'])
                return false;
            node = node->links[word[i] - 'a'];
        }
        return node->flag;
    }
    bool ifPrefixExists(string &word){
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            string temp = word.substr(0,i+1);
            if(!search(temp))
            return false;
        }
        return true;
    }
};

class Solution
{

public:
    string longestWord(vector<string> &words)
    {
        Trie obj;
        string ans = "";
        for (auto &x : words)
        {
            obj.insert(x);
        }
        for (auto &x : words)
        {
            int l = x.length();
            if (obj.ifPrefixExists(x))
            {
                if (l>ans.length())
                    ans = x;
                else if ((l == ans.length()) && (x<ans))
                    ans = x;
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
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    Solution obj;
    cout << obj.longestWord(words);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}