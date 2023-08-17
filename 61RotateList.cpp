#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

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
    ListNode *rotateRight(ListNode *head, int k)
    {   
        if(!head)
        return head;
        int size = 0;
        ListNode *curr = head, *prev = nullptr;
        while (curr)
        {
            ++size;
            prev = curr;
            curr = curr->next;
        }
        k = k%size;
        prev->next = head;
        curr = head;
        for (int i = 1; i < size - k; i++)
        {
            curr = curr->next;
        }
        head = curr ->next;
        curr->next = nullptr;
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