#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1;

  while (start < end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[mid + 1])
    {
      // in dec part of the array
      end = mid;
    }
    else
    {
      start = mid + 1;
    }
  }

  return start;
}

int main()
{

  return 0;
}