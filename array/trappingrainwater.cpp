#include <bits/stdc++.h>
using namespace std;

// formula min(leftMax, rightMax) - ownHeight

// T - O(n^2) S - O(1)
int method1(int arr[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int leftMax = *max_element(arr, arr + i + 1);
    int rightMax = *max_element(arr + i, arr + n);
    sum += min(leftMax, rightMax) - arr[i];
  }
  return sum;
}

// T - O(3N) -> O(N) S -> O(2N) -> O(N)
int method2(int arr[], int n)
{
  // Using Prefix and Suffix Arrays
  int sum = 0, left[n], right[n];

  left[0] = arr[0];
  for (int i = 1; i < n; i++)
  {
    left[i] = max(left[i - 1], arr[i]);
  }

  right[0] = arr[n - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    right[i] = max(right[i + 1], arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    sum += min(left[i], right[i]) - arr[i];
  }

  return sum;
}

int method3(int arr[], int n)
{
  int sum = 0, leftMax = 0, rightMax = 0, start = 0, end = n - 1;
  while (start <= end)
  {
    if (arr[start] <= arr[end])
    {
      if (arr[start] >= leftMax)
        leftMax = arr[start];
      else
        sum += leftMax - arr[start];
      start++;
    }
    else
    {
      if (arr[end] >= rightMax)
        rightMax = arr[end];
      else
        sum += rightMax - arr[end];
      end--;
    }
  }
  return sum;
}

int main()
{
  int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Water Trapped: " << method3(arr, n) << endl;
  return 0;
}