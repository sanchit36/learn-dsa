#include <bits/stdc++.h>
using namespace std;

void rearrange(int nums[], int n)
{
  for (int l = 0, r = 0; r < n; r++)
  {
    if (nums[r] < 0)
    {
      swap(nums[l++], nums[r]);
    }
  }
}

// 0...r-1 -> -ve
// r...n-1 -> +ve

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
  int n = sizeof(arr) / sizeof(arr[0]);
  rearrange(arr, n);
  printArray(arr, n);
  return 0;
}