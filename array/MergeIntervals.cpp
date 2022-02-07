#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // T -> O(nlog(n)) S -> O(n)
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> mergeIntervals;
    if (intervals.size() == 0)
    {
      return mergeIntervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for (auto it : intervals)
    {
      if (it[0] <= tempInterval[1])
      {
        tempInterval[1] = max(tempInterval[1], it[1]);
      }
      else
      {
        mergeIntervals.push_back(tempInterval);
        tempInterval = it;
      }
    }
    mergeIntervals.push_back(tempInterval);
    return mergeIntervals;
  }
};

int main()
{

  return 0;
}