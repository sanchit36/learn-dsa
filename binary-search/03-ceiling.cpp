#include <bits/stdc++.h>
using namespace std;

// return the index of smallest number >= target
int floor(vector<int> &arr, int target)
{
  int s = 0, e = arr.size() - 1;

  if (target > arr[e])
  {
    return -1;
  }

  while (s <= e)
  {
    int mid = s + (e - s) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }

    if (target > arr[mid])
    {
      s = mid + 1;
    }
    else
    {
      e = mid - 1;
    }
  }
  return s;
}

int main()
{
  vector<int> arr = {-14, -10, 2, 3, 4, 6, 10, 14, 18, 30, 69, 80};
  int target;
  cin >> target;
  cout << floor(arr, target) << endl;
  return 0;
}