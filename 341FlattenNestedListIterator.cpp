#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    vector<int> res;
    void flatten(vector<NestedInteger> list){
        for(auto ele:list){
            if(ele.isInteger()) res.push_back(ele.getInteger());
            else flatten(ele.getList());
        }
    }
    int ind;
    int size;
    public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
        ind = 0;
        size = res.size();
    }

    int next()
    {
        return res[ind++];
    }

    bool hasNext()
    {
        return ind < size;
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