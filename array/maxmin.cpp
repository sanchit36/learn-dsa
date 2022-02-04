#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxminIt(int arr[], int n)
{
  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int el = arr[i];
    if (min > el)
      min = el;
    if (max < el)
      max = el;
  }
  return {max, min};
}

pair<int, int> maxminRe(int arr[], int n, int idx)
{
  if (idx == n)
    return {INT_MIN, INT_MAX};
  pair<int, int> ans = maxminRe(arr, n, idx + 1);
  int el = arr[idx];
  int min = ans.second > el ? el : ans.second, max = ans.first < el ? el : ans.first;
  return {max, min};
}

int main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int n = sizeof(arr) / sizeof(arr[0]);
  pair<int, int> ansIt = maxminIt(arr, n);
  cout << "MAX: " << ansIt.first << " "
       << "MIN: " << ansIt.second << endl;
  pair<int, int> ansRe = maxminRe(arr, n, 0);
  cout << "MAX: " << ansRe.first << " "
       << "MIN: " << ansRe.second << endl;
  return 0;
}