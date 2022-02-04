#include <bits/stdc++.h>
using namespace std;

/*
 @return  index of the first occurrence of target
          or -1 if no such occurrence exists
*/
int binarySearch(vector<int> &arr, int target)
{
  int start = 0;
  int end = arr.size() - 1;

  while (start <= end)
  {
    // int mid = (start + end)/2 // might possible that (start + end) exceeds the range of int in cpp
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

int main()
{
  vector<int> arr = {-18, -12, -4, 0, 2, 3, 4, 15, 16, 18, 22, 45, 89};
  int target;
  cin >> target;
  int ans = binarySearch(arr, target);
  cout << ans << endl;
  return 0;
}
