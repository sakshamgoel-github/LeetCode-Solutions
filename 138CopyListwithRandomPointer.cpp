#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> ump;
        Node *ptr1 = head;

        while (ptr1)
        {
            Node *copy = new Node(ptr1->val);
            ump[ptr1] = copy;
            ptr1 = ptr1->next;
        }
        Node *ptr2 = new Node(0);
        Node *ans = ptr2;
        ptr1 = head;
        while (ptr1)
        {
            ptr2 -> next = ump[ptr1];
            ptr2-> next -> random = ump[ptr1->random];
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ans->next;
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