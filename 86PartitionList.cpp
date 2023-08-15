#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(), *s = small;
        ListNode *greater = new ListNode(), *g = greater;
        ListNode *curr = head;
        while (curr)
        {
            if (curr->val < x)
            {
                s->next = curr;
                s = s->next;
            }
            else
            {
                g->next = curr;
                g = g->next;
            }
            curr = curr->next;
        }
        g -> next = nullptr;
        s->next = greater->next;
        return small -> next;
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