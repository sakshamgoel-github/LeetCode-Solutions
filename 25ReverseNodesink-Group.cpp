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
    ListNode *getK(ListNode *curr, int k)
    {
        while (curr && k)
        {
            k--;
            curr = curr->next;
        }
        return curr;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head), *groupPrev = dummy, *groupNext;
        while (1)
        {
            ListNode *K = getK(groupPrev, k);
            if (!K)
                break;
            groupNext = K->next;
            ListNode *prev = groupNext, *curr = groupPrev->next;
            while (curr != groupNext)
            {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode *temp = groupPrev->next;
            groupPrev->next = K;
            groupPrev = temp;
        }
        return dummy->next;
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