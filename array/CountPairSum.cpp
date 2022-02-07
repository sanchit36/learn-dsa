#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
  int pairs = 0;
  unordered_map<int, int> map;

  for (int i = 0; i < n; i++)
  {
    int key = k - arr[i];
    if (map.find(key) != map.end())
    {
      pairs += map[key];
    }
    if (map.find(arr[i]) == map.end())
    {
      map[arr[i]] = 1;
    }
    else
    {
      map[arr[i]]++;
    }
  }
  return pairs;
}

int main()
{
  return 0;
}