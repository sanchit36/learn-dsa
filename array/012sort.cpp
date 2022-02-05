#include <bits/stdc++.h>
using namespace std;

// couting sort, T O(2n) -> O(n) S O(1)
void method1(int arr[], int n)
{
  int count0 = 0, count1 = 0, count2 = 0;

  for (int i = 0; i < n; i++)
  {
    switch (arr[i])
    {
    case 0:
      count0++;
      break;
    case 1:
      count1++;
      break;
    case 2:
      count2++;
      break;
    }
  }

  for (int i = 0; i < count0; i++)
  {
    arr[i] = 0;
  }
  for (int i = count0; i < count0 + count1; i++)
  {
    arr[i] = 1;
  }
  for (int i = count0 + count1; i < count0 + count1 + count2; i++)
  {
    arr[i] = 2;
  }
}

// 0..low-1 -> 0
// high+1...n-1 -> 2
// Dutch's National Flag
// T -> O(n) S -> O(1) in one pass
void method2(int nums[], int n)
{
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high)
  {
    switch (nums[mid])
    {
    case 0:
      swap(nums[low], nums[mid]);
      low++;
      mid++;
      break;
    case 1:
      mid++;
      break;
    case 2:
      swap(nums[high], nums[mid]);
      high--;
      break;
    }
  }
}

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
  int n = 5;
  int arr[] = {0, 2, 1, 2, 0};
  method2(arr, n);
  printArray(arr, n);
  return 0;
}