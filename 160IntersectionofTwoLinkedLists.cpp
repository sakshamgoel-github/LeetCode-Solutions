#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int len(ListNode *node)
    {
        int size = 0;
        while (node)
        {
            ++size;
            node = node->next;
        }
        return size;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int a = len(headA);
        int b = len(headB);
        if (a > b)
        {
            for (int i = 0; i < a - b; i++)
            {
                headA = headA->next;
            }
        }
        else
        {
            for (int i = 0; i < b - a; i++)
            {
                headB = headB->next;
            }
        }
        while (headA && headB)
        {
            if(headA == headB)
            return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
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