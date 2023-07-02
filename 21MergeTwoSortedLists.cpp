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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;
        else
        {
            ListNode *curr1, *curr2, *ptr,*res;
            if (list1->val <= list2->val)
            {
                curr1 = list1;
                curr2 = list2;
            }
            else {
                curr1 = list2;
                curr2 = list1;
            }
            res = curr1;
            while (curr1 && curr2)
            {
                while (curr1 && curr1->val<=curr2->val)
                {
                    ptr = curr1;
                    curr1 = curr1->next;
                }
                ptr->next = curr2;
                swap(curr1,curr2);                
            }
            return res;
        }
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