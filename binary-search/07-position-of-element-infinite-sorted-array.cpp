#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target, int start, int end)
{
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}

int ans(vector<int> &arr, int target)
{
  int start = 0, end = 1;

  while (target > arr[end])
  {
    int newStart = end + 1;
    end = end + (end - start + 1) * 2;
    start = newStart;
  }

  return binarySearch(arr, target, start, end);
}

int main()
{
  vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
  int target = 10;
  cout << ans(arr, target) << endl;
  return 0;
}