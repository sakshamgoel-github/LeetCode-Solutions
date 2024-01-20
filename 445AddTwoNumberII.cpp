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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        ListNode *temp = l1;
        while(temp){
            s1.push(temp->val);
            temp = temp -> next;
        }
        temp = l2;
        while(temp){
            s2.push(temp -> val);
            temp = temp -> next;
        }
        int carry = 0,sum = 0;
        ListNode *ans = new ListNode();
        while(s1.size() || s2.size()){
            if(s1.size()){
                sum += s1.top();
                s1.pop();
            }
            if(s2.size()){
                sum += s2.top();
                s2.pop();
            }
            sum += carry;
            ans -> val = sum%10;
            carry = sum /10;
            ListNode *newNode = new ListNode(carry);
            newNode -> next = ans;
            ans = newNode;
            sum = 0;
        }
        if (!carry)
        return ans -> next;
        return ans;
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