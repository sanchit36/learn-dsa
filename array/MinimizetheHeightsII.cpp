#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
  sort(arr, arr + n);
  int maxDiff = arr[n - 1] - arr[0];
  int smallest = arr[0] + k;
  int largest = arr[n - 1] - k;

  int newMax, newMin;
  for (int i = 1; i < n; i++)
  {
    newMax = max(largest, arr[i - 1] + k);
    newMin = min(smallest, arr[i] - k);
    if (newMin < 0)
      continue;
    maxDiff = min(maxDiff, newMax - newMin);
  }

  return maxDiff;
}

int main()
{
  int K = 2, N = 4;
  int Arr[] = {1, 5, 8, 10};
  cout << getMinDiff(Arr, N, K) << endl;
  return 0;
}