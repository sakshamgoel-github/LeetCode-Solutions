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
    void reorderList(ListNode *head)
    {
        int size = 0;
        ListNode *curr = head, *prev = nullptr;
        while (curr)
        {
            curr = curr->next;
            ++size;
        }
        curr = head;
        for (int i = 0; i < size / 2 + 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        while (curr)
        {
            ListNode *agla = curr->next;
            curr->next = prev;
            prev = curr;
            curr = agla;
        }
        curr = head;
        while (prev -> next)
        {
            ListNode *cNext = curr->next;
            ListNode *pNext = prev->next;
            curr->next = prev;
            prev->next = cNext;
            prev = pNext;
            curr = cNext;
        }
        return;
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