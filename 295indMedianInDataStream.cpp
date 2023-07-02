#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

public:
    MedianFinder()
    {
        size = 0;
    }

    void addNum(int num)
    {
        if (!maxHeap.size())
            maxHeap.push(num);

        else if (maxHeap.size() == minHeap.size())
        {
            if (num <= minHeap.top())
                maxHeap.push(num);
            else
            {
                int t = minHeap.top();
                minHeap.pop();
                maxHeap.push(t);
                minHeap.push(num);
            }
        }
        else
        {
            if (num >= maxHeap.top())
                minHeap.push(num);
            else
            {
                int t = maxHeap.top();
                maxHeap.pop();
                minHeap.push(t);
                maxHeap.push(num);
            }
        }
        ++size;
    }

    double findMedian()
    {
        if (size & 1)
            return double(maxHeap.top());

        return double(maxHeap.top() + minHeap.top()) / 2.0;
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