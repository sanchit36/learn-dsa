#include <bits/stdc++.h>
using namespace std;

void iterative(int arr[], int n)
{
  int start = 0, end = n - 1;
  while (start < end)
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void recursive(int arr[], int n, int start, int end)
{
  if (start >= end)
    return;
  swap(arr[start], arr[end]);
  recursive(arr, n, start + 1, end - 1);
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
  // int arr[] = {4, 5, 1, 2};
  int arr[] = {1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
  iterative(arr, n);
  printArray(arr, n);
  recursive(arr, n, 0, n - 1);
  printArray(arr, n);
  return 0;
}