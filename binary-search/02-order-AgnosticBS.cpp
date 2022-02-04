#include <bits/stdc++.h>
using namespace std;

/*
 @return  index of the first occurrence of target
          or -1 if no such occurrence exists
*/
int orderAgnosticBS(vector<int> &arr, int target)
{
  int start = 0;
  int end = arr.size() - 1;

  // find if the array is ascending or descending.
  bool isAscending = arr[start] < arr[end];

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }

    if (isAscending)
    {
      if (target > arr[mid])
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
    else
    {
      if (target < arr[mid])
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  // vector<int> arr = {-18, -12, -4, 0, 2, 3, 4, 15, 16, 18, 22, 45, 89};
  vector<int> arr = {99, 80, 75, 22, 10, 3, 2, -10};
  int target;
  cin >> target;
  int ans = orderAgnosticBS(arr, target);
  cout << ans << endl;
  return 0;
}
