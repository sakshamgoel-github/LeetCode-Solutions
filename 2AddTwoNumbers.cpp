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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *t = ans;
        int carry = 0;
        while (l1 && l2)
        {
            int value = l1->val + l2->val + carry;
            t->next = new ListNode(value % 10);
            carry = value / 10;
            l1 = l1->next;
            l2 = l2->next;
            t = t->next;
        }
        while (l1)
        {
            int value = l1->val + carry;
            t->next = new ListNode(value % 10);
            carry = value / 10;
            l1 = l1->next;
            t = t->next;
        }
        while (l2)
        {
            int value = l2->val + carry;
            t->next = new ListNode(value % 10);
            carry = value / 10;
            l2 = l2->next;
            t = t->next;
        }
        if (carry)
            t->next = new ListNode(carry);
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