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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int size = 0;
        ListNode *curr = head;
        while (curr)
        {
            ++size;
            curr = curr->next;
        }
        curr = head;
        int ind = 1,val1,val2;
        while (curr)
        {
            if(ind == k)
            val1 = curr->val;
            if (ind == (size-k+1))
            val2 = curr->val;
            curr=curr->next;
            ++ind;
        }        
        curr = head;
        ind = 1;
        while(curr){
            if(ind == k)
            curr->val = val2;
            if (ind == (size-k+1))
            curr->val = val2;
            curr=curr->next;
            ++ind;
        }
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