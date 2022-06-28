#include <bits/stdc++.h>
using namespace std;

class Heap
{
    int i, size;
    void insert(vector<int> &pq)
    {
        int CI = size - 1;
        while (CI > 0)
        {
            int PI = (CI - 1) / 2;
            if (pq[CI] < pq[PI])
                swap(pq[CI], pq[PI]);
            CI = PI;
        }
    }
    void remove(vector<int> &pq)
    {
        swap(pq[0], pq[size - 1]);
        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && pq[minIndex] > pq[rightChildIndex])
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
    }

public:
    Heap(vector<int> &arr)
    {
        size = 1;
        for (i = 1; i < arr.size(); i++)
        {
            size++;
            insert(arr);
        }
        for (i = 0; i < arr.size(); i++)
        {
            remove(arr);
        }
    }
};

int main()
{
    vector<int> arr = {10, 5, 8, 1, 4};
    Heap h = Heap(arr);
    for (auto num : arr)
    {
        cout << num << ", ";
    }
    return 0;
}