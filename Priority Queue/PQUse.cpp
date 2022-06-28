#include <bits/stdc++.h>
#include <queue>
using namespace std;

void kSortedArray(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

void kSmallestElements(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (pq.top() > input[i])
        {
            pq.pop();
            pq.push(input[i]);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << ", ";
        pq.pop();
    }
}

int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int n = 5;
    int k = 3;
    kSmallestElements(input, n, k);
    return 0;
}