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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *aPtr = list1;        
        ListNode *bPtr = list1;
        for (int i = 1; i < a; i++)
        {
            aPtr = aPtr -> next;
        }
        for (int i = 0; i < b; i++)
        {
            bPtr = bPtr->next;
        }
        bPtr = bPtr -> next;
        aPtr -> next = list2;
        ListNode *curr = list2;
        while (curr -> next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = bPtr;
        return list1;
        
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