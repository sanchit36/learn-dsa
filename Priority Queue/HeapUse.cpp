#include <bits/stdc++.h>
using namespace std;
#include "PriorityQueue.h"

int main()
{
    PriorityQueue pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);

    cout << pq.getSize() << endl;
    cout << pq.getMin() << endl;

    while (!pq.isEmpty())
    {
        cout << pq.removeMin() << ", ";
    }

    return 0;
}