#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void insert(stack<int> &st, int ele)
{
    if (st.empty() || st.top() <= ele)
    {
        st.push(ele);
        return;
    }
    int t = st.top();
    st.pop();
    insert(st, ele);
    st.push(t);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int t = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, t);
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}