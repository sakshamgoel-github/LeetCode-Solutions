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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *curr = head;
        while (curr)
        {
            ++size;
            curr = curr->next;
        }
        curr  = head;
        if (!(size - n))
            return head->next;
        for (int i = 1; i < size - n; i++)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
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