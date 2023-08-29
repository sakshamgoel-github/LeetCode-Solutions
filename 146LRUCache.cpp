#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class LRUCache
{
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head;
    node *tail;

    int cap;
    unordered_map<int, node *> ump;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void insertNode(node *newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deleteNode(node *N)
    {   
        node* delprev = N->prev;
        node* delnext = N->next;
        delprev->next = delnext;
        delnext->prev = delprev;        
    }
    int get(int key)
    {
        if (ump.find(key) != ump.end())
        {
            node *t = ump[key];
            int v = t->val;
            int k = t->key;
            ump.erase(key);
            deleteNode(t);
            insertNode(t);
            ump[key] = t;
            return v;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(ump.find(key) != ump.end()){
            node *t = ump[key];
            ump.erase(key);
            deleteNode(t);
        }
        if(ump.size() == cap){
            ump.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node *t = new node(key,value);
        insertNode(t);
        ump[key] = t;
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