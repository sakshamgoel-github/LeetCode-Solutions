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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *curr = head;
        while (curr->next != NULL)
        {
            ListNode *ptr1 = curr->next;
            ListNode *ptr2 = ptr1->next;
            while (ptr2->val != 0)
            {
                ptr1->val += ptr2->val;
                ptr2 = ptr2->next;
            }
            ptr1->next = ptr2->next;
            curr = ptr2;
        }
        return head->next;
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