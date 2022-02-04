#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int target)
{
  int s = 0, e = arr.size() - 1;

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
  return e;
}

int main()
{
  vector<int> arr = {-14, -10, 2, 3, 4, 6, 10, 14, 18, 30, 69, 80};
  int target;
  cin >> target;
  cout << floor(arr, target) << endl;
  return 0;
}