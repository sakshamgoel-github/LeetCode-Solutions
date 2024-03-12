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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        unordered_map<int, ListNode *> ump;
        int sum = 0;

        ListNode *dummy = new ListNode(0, head);
        ump[0] = dummy;
        
        ListNode *curr = head;
        
        while (curr)
        {
            sum += curr->val;
            if (ump.find(sum) != ump.end())
            {   
                ListNode *temp = ump[sum];
                int psum = sum;
                while (temp != curr)
                {
                    temp = temp->next;
                    psum += temp->val;
                    if (temp != curr)
                        ump.erase(psum);
                }
                ump[sum]->next = curr->next;
            }
            else{
                ump[sum] = curr;
            }
            curr=curr->next;
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