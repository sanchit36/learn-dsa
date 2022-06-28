#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue() {}
    bool isEmpty() { return pq.empty(); }
    int getSize() { return pq.size(); }
    int getMin() { return isEmpty() ? 0 : pq[0]; }
    void insert(int val)
    {
        pq.push_back(val);
        int CI = getSize() - 1;
        while (CI > 0)
        {
            int PI = (CI - 1) / 2;
            if (pq[CI] < pq[PI])
                swap(pq[CI], pq[PI]);
            else
                break;
            CI = PI;
        }
    }
    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
                break;
            swap(pq[minIndex], pq[parentIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};