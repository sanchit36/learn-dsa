#include <bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{
  //write your code here
}

int main()
{
  int n, tar;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cin >> tar;
  printTargetSumSubsets(arr, 0, "", 0, tar);
}