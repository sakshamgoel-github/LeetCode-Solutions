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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        vector<int> t;
        int i = 0;
        while (curr->next)
        {
            if (prev)
            {
                if ((curr->val > prev->val && curr->val > curr->next->val) ||
                    (curr->val < prev->val && curr->val < curr->next->val))
                {
                    t.push_back(i);
                }
            }
            prev = curr;
            curr = curr->next;
            ++i;
        }
        if (t.size() == 0)
            return {-1, -1};
        if (t.size() == 1)
            return {-1, -1};
        int maxi = t.back() - t[0];
        int mini = INT_MAX;
        for (int i = 0; i < t.size() - 1; ++i)
        {
            if (t[i + 1] - t[i] < mini)
                mini = t[i + 1] - t[i];
        }
        return {mini, maxi};
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