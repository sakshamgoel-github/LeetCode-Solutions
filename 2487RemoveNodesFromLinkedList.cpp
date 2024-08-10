#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *reverse(ListNode * head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr){
            ListNode *cnext = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = cnext;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int maxi = -1;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr){
            if(maxi <= curr -> val){
                maxi = curr -> val;
                prev = curr;
                curr = curr -> next;
            }
            else{
                prev -> next = curr -> next;
                curr = curr -> next;
            }
        }
        head = reverse(head);
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